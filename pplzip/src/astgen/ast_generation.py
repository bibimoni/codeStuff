"""
AST Generation module for OPLang programming language.
This module contains the ASTGeneration class that converts parse trees
into Abstract Syntax Trees using the visitor pattern.
"""

from functools import reduce
from build.OPLangVisitor import OPLangVisitor
from build.OPLangParser import OPLangParser
from src.utils.nodes import *


class ASTGeneration(OPLangVisitor):
    def visitProgram(self, ctx: OPLangParser.ProgramContext):
        return Program(self.visit(ctx.classlist()))

    def visitClasslist(self, ctx: OPLangParser.ClasslistContext):
        return (
            [self.visit(ctx.clas())] + self.visit(ctx.classlist())
            if ctx.getChildCount() == 2
            else [self.visit(ctx.clas())]
        )

    def visitClas(self, ctx: OPLangParser.ClasContext):
        cur = ClassDecl(ctx.ID(0).getText(), ctx.ID(1), self.visit(ctx.members()))
        return cur

    def visitMembers(self, ctx: OPLangParser.MembersContext):
        return (
            []
            if ctx.getChildCount() == 0
            else [self.visit(ctx.member())] + self.visit(ctx.members())
        )

    def visitMember(self, ctx: OPLangParser.MemberContext):
        if ctx.attributedecl():
            return self.visit(ctx.attributedecl())
        elif ctx.methoddecl():
            return self.visit(ctx.methoddecl())
        elif ctx.constructor():
            return self.visit(ctx.constructor())
        else:
            return self.visit(ctx.destructor())

    def visitConstructor(self, ctx: OPLangParser.ConstructorContext):
        return ConstructorDecl(
            ctx.ID().getText(), self.visit(ctx.paramlist()), self.visit(ctx.blockstmt())
        )

    def visitDestructor(self, ctx: OPLangParser.DestructorContext):
        return DestructorDecl(ctx.ID().getText(), self.visit(ctx.blockstmt()))

    def visitMethoddecl(self, ctx: OPLangParser.MethoddeclContext):
        taipu = self.visit(ctx.typevoid())
        if ctx.AMP():
            taipu = ReferenceType(taipu)
        # if ctx.STATIC() and self.cur_class:
        #     self.static_methods.append((self.cur_class, ctx.ID().getText()))
        return MethodDecl(
            True if ctx.STATIC() else False,
            taipu,
            ctx.ID().getText(),
            self.visit(ctx.paramlist()),
            self.visit(ctx.blockstmt()),
        )

    def visitStmtlist(self, ctx: OPLangParser.StmtlistContext):
        return (
            [self.visit(ctx.stmt())] + self.visit(ctx.stmtlist()) if ctx.stmt() else []
        )

    def visitStmt(self, ctx: OPLangParser.StmtContext):
        if ctx.blockstmt():
            return self.visit(ctx.blockstmt())
        elif ctx.vardecl():
            return self.visit(ctx.vardecl())
        elif ctx.assignstmt():
            return self.visit(ctx.assignstmt())
        elif ctx.ifstmt():
            return self.visit(ctx.ifstmt())
        elif ctx.forstmt():
            return self.visit(ctx.forstmt())
        elif ctx.breakstmt():
            return self.visit(ctx.breakstmt())
        elif ctx.continuestmt():
            return self.visit(ctx.continuestmt())
        elif ctx.returnstmt():
            return self.visit(ctx.returnstmt())
        elif ctx.methodinvokestmt():
            return self.visit(ctx.methodinvokestmt())

    def visitBlockstmt(self, ctx: OPLangParser.BlockstmtContext):
        return BlockStatement(
            filter(lambda x: isinstance(x, VariableDecl), self.visit(ctx.stmtlist())),
            filter(
                lambda x: not isinstance(x, VariableDecl), self.visit(ctx.stmtlist())
            ),
        )

    def visitVardecl(self, ctx: OPLangParser.VardeclContext):
        taipu = self.visit(ctx.type_())
        if ctx.AMP():
            taipu = ReferenceType(taipu)
            return VariableDecl(
                True if ctx.FINAL() else False,
                taipu,
                self.visit(ctx.varlist2()),
            )
        else:
            return VariableDecl(
                True if ctx.FINAL() else False,
                taipu,
                self.visit(ctx.varlist()),
            )

    def visitVarlist(self, ctx: OPLangParser.VarlistContext):
        return (
            [self.visit(ctx.varitem())]
            if not ctx.COMMA()
            else [self.visit(ctx.varitem())] + self.visit(ctx.varlist())
        )

    def visitVaritem(self, ctx: OPLangParser.VaritemContext):
        return Variable(
            ctx.ID().getText(), self.visit(ctx.expr()) if ctx.expr() else None
        )

    def visitVarlist2(self, ctx: OPLangParser.Varlist2Context):
        return (
            [self.visit(ctx.varitem2())]
            if not ctx.COMMA()
            else [self.visit(ctx.varitem2())] + self.visit(ctx.varlist2())
        )

    def visitVaritem2(self, ctx: OPLangParser.Varitem2Context):
        return Variable(ctx.ID().getText(), self.visit(ctx.expr()))

    def visitAssignstmt(self, ctx: OPLangParser.AssignstmtContext):
        post = self.visit(ctx.post_expr())
        if isinstance(post, Identifier):
            return AssignmentStatement(
                IdLHS(post.name),
                self.visit(ctx.expr()),
            )
        else:
            return AssignmentStatement(
                PostfixLHS(self.visit(ctx.post_expr())),
                self.visit(ctx.expr()),
            )

    def visitIfstmt(self, ctx: OPLangParser.IfstmtContext):
        return IfStatement(
            self.visit(ctx.expr()),
            self.visit(ctx.stmt(0)),
            None if not ctx.ELSE() else self.visit(ctx.stmt(1)),
        )

    def visitForstmt(self, ctx: OPLangParser.ForstmtContext):
        return ForStatement(
            ctx.ID().getText(),
            self.visit(ctx.expr(0)),
            ctx.TO().getText() if ctx.TO() else ctx.DOWNTO().getText(),
            self.visit(ctx.expr(1)),
            self.visit(ctx.stmt()),
        )

    def visitBreakstmt(self, ctx: OPLangParser.BreakstmtContext):
        return BreakStatement()

    def visitContinuestmt(self, ctx: OPLangParser.ContinuestmtContext):
        return ContinueStatement()

    def visitReturnstmt(self, ctx: OPLangParser.ReturnstmtContext):
        return ReturnStatement(self.visit(ctx.expr()))

    def visitMethodinvokestmt(self, ctx: OPLangParser.MethodinvokestmtContext):
        first = self.visit(ctx.expr())
        arg_list = self.visit(ctx.arg_list())
        # if (
        #     isinstance(first, Identifier)
        #     and (first.name, ctx.ID().getText()) in self.static_methods
        # ):
        #     return MethodInvocationStatement(
        #         StaticMethodInvocation(first.name, ctx.ID().getText(), arg_list)
        #     )
        if not isinstance(first, PostfixExpression):
            first = PostfixExpression(first, [])
        first.postfix_ops.append(MethodCall(ctx.ID().getText(), arg_list))
        # return MethodInvocationStatement(MethodInvocation(first))
        return MethodInvocationStatement(first)

    def visitTypevoid(self, ctx: OPLangParser.TypevoidContext):
        if ctx.VOID():
            return PrimitiveType(ctx.VOID().getText())
        taipu = self.visit(ctx.base_type())
        val = self.visit(ctx.type_array_suff())
        if val is not None:
            taipu = ArrayType(taipu, val)
        return taipu

    def visitAttributedecl(self, ctx: OPLangParser.AttributedeclContext):
        is_static, is_final = self.visit(ctx.attrmods())
        taipu = self.visit(ctx.type_())
        if ctx.AMP():
            taipu = ReferenceType(taipu)

        attr_list = self.visit(ctx.attributelist())
        # if is_static and self.cur_class:
        #     self.static_members += [(self.cur_class, attr.name) for attr in attr_list]

        return AttributeDecl(is_static, is_final, taipu, attr_list)

    def visitAttributelist(self, ctx: OPLangParser.AttributelistContext):
        return (
            [self.visit(ctx.attribute())] + self.visit(ctx.attributelist())
            if ctx.COMMA()
            else [self.visit(ctx.attribute())]
        )

    def visitAttribute(self, ctx: OPLangParser.AttributeContext):
        return Attribute(
            ctx.ID().getText(), self.visit(ctx.expr()) if ctx.ASSIGN() else None
        )

    def visitAttrmods(self, ctx: OPLangParser.AttrmodsContext):
        return (ctx.STATIC() is not None, ctx.FINAL() is not None)

    def visitParamlist(self, ctx: OPLangParser.ParamlistContext):
        return self.visit(ctx.paramprime()) if ctx.paramprime() else []

    def visitParamprime(self, ctx: OPLangParser.ParamprimeContext):
        return (
            self.visit(ctx.param()) + self.visit(ctx.paramprime())
            if ctx.SEMI()
            else self.visit(ctx.param())
        )

    def visitParam(self, ctx: OPLangParser.ParamContext):
        taipu = self.visit(ctx.type_())
        if ctx.AMP():
            taipu = ReferenceType(taipu)
        return [Parameter(taipu, x.name) for x in self.visit(ctx.idlist())]

    def visitType(self, ctx: OPLangParser.TypeContext):
        taipu = self.visit(ctx.base_type())
        val = self.visit(ctx.type_array_suff())
        if val is not None:
            taipu = ArrayType(taipu, val)
        return taipu

    def visitType_array_suff(self, ctx: OPLangParser.Type_array_suffContext):
        if ctx.INT():
            return int(ctx.INT().getText())
        return None

    def visitBase_type(self, ctx: OPLangParser.Base_typeContext):
        if ctx.INT_LIT():
            return PrimitiveType(ctx.INT_LIT().getText())
        elif ctx.FLOAT_LIT():
            return PrimitiveType(ctx.FLOAT_LIT().getText())
        elif ctx.BOOL_LIT():
            return PrimitiveType(ctx.BOOL_LIT().getText())
        elif ctx.STRING_LIT():
            return PrimitiveType(ctx.STRING_LIT().getText())
        elif ctx.ID():
            return ClassType(ctx.ID().getText())
        else:
            return None

    def visitIdlist(self, ctx: OPLangParser.IdlistContext):
        return (
            [Identifier(ctx.ID().getText())] + self.visit(ctx.idlist())
            if ctx.COMMA()
            else [Identifier(ctx.ID().getText())]
        )

    def visitExpr(self, ctx: OPLangParser.ExprContext):
        return self.visit(ctx.relational_expr())

    def visitOrand_expr(self, ctx: OPLangParser.Orand_exprContext):
        right = self.visit(ctx.addsub_expr())
        if ctx.getChildCount() == 1:
            return right
        left = self.visit(ctx.orand_expr())
        return BinaryOp(left, "||" if ctx.OR_OR() else "&&", right)

    def visitEq_expr(self, ctx):
        left = self.visit(ctx.orand_expr())
        ret = self.visit(ctx.eq_expr_tail())
        if ret is None:
            return left
        op, right = ret
        return BinaryOp(left, op, right)

    def visitEq_expr_tail(self, ctx: OPLangParser.Eq_expr_tailContext):
        if ctx.getChildCount() == 0:
            return None
        else:
            return ("==" if ctx.EQEQ() else "!=", self.visit(ctx.orand_expr()))

    def visitRelational_expr(self, ctx: OPLangParser.Relational_exprContext):
        left = self.visit(ctx.eq_expr())
        ret = self.visit(ctx.relational_expr_tail())
        if ret is None:
            return left
        op, right = ret
        return BinaryOp(left, op, right)

    def visitRelational_expr_tail(self, ctx: OPLangParser.Relational_expr_tailContext):
        if ctx.getChildCount() == 0:
            return None
        else:
            if ctx.LT():
                op = "<"
            elif ctx.GT():
                op = ">"
            elif ctx.GE():
                op = ">="
            elif ctx.LE():
                op = "<="
        right = self.visit(ctx.eq_expr())
        return (op, right)

    def visitAddsub_expr(self, ctx: OPLangParser.Addsub_exprContext):
        if ctx.addsub_expr():
            return BinaryOp(
                self.visit(ctx.addsub_expr()),
                "+" if ctx.PLUS() else "-",
                self.visit(ctx.muldiv_expr()),
            )
        else:
            return self.visit(ctx.muldiv_expr())

    def visitMuldiv_expr(self, ctx: OPLangParser.Muldiv_exprContext):
        if ctx.muldiv_expr():
            if ctx.STAR():
                op = "*"
            elif ctx.SLASH():
                op = "/"
            elif ctx.PERCENT():
                op = "%"
            elif ctx.BACKSLASH():
                op = "\\"
            return BinaryOp(
                self.visit(ctx.muldiv_expr()),
                op,
                self.visit(ctx.caret_expr()),
            )
        else:
            return self.visit(ctx.caret_expr())

    def visitCaret_expr(self, ctx: OPLangParser.Caret_exprContext):
        if ctx.CARET():
            return BinaryOp(
                self.visit(ctx.caret_expr()),
                "^",
                self.visit(ctx.unary_expr()),
            )
        return self.visit(ctx.unary_expr())

    def visitUnary_expr(self, ctx: OPLangParser.Unary_exprContext):
        if ctx.PLUS() or ctx.MINUS() or ctx.BANG():
            if ctx.PLUS():
                op = "+"
            elif ctx.BANG():
                op = "!"
            elif ctx.MINUS():
                op = "-"
            return UnaryOp(op, self.visit(ctx.unary_expr()))
        else:
            return self.visit(ctx.post_expr())

    def visitPrimary(self, ctx: OPLangParser.PrimaryContext):
        if ctx.INT():
            return IntLiteral(int(ctx.INT().getText()))
        elif ctx.FLOAT():
            return FloatLiteral(float(ctx.FLOAT().getText()))
        elif ctx.BOOLEAN():
            return BoolLiteral(ctx.BOOLEAN().getText() == "true")
        elif ctx.NIL():
            return NilLiteral()
        elif ctx.ID():
            return Identifier(ctx.ID().getText())
        elif ctx.STRING():
            return StringLiteral(ctx.STRING().getText())
        elif ctx.THIS():
            return ThisExpression()
        elif ctx.expr():
            return ParenthesizedExpression(self.visit(ctx.expr()))
        elif ctx.class_create_expr():
            return self.visit(ctx.class_create_expr())
        elif ctx.array_expr():
            return ArrayLiteral(self.visit(ctx.array_expr()))
        return "error"

    def visitPost_expr(self, ctx: OPLangParser.Post_exprContext):
        prime = self.visit(ctx.primary())
        post_expr_tail = self.visit(ctx.post_expr_tail())
        if len(post_expr_tail) == 0:
            return prime
        # elif not isinstance(prime, Identifier):
        #     return PostfixExpression(prime, post_expr_tail)
        # elif (
        #     isinstance(post_expr_tail[0], MemberAccess)
        #     and (prime.name, post_expr_tail[0].member_name) in self.static_members
        # ):
        #     res = StaticMemberAccess(prime.name, post_expr_tail[0].member_name)
        #     if len(post_expr_tail) > 1:
        #         res = PostfixExpression(res, post_expr_tail[1:])
        #     return res
        # elif (
        #     isinstance(post_expr_tail[0], MethodCall)
        #     and (prime.name, post_expr_tail[0].method_name) in self.static_methods
        # ):
        #     res = StaticMethodInvocation(
        #         prime.name, post_expr_tail[0].method_name, post_expr_tail[0].args
        #     )
        #     if len(post_expr_tail) > 1:
        #         res = PostfixExpression(res, post_expr_tail[1:])
        #     return res
        return PostfixExpression(prime, post_expr_tail)

    def visitPost_expr_tail(self, ctx: OPLangParser.Post_expr_tailContext):
        return (
            []
            if ctx.getChildCount() == 0
            else [self.visit(ctx.post_suffix())] + self.visit(ctx.post_expr_tail())
        )

    def visitPost_suffix(self, ctx: OPLangParser.Post_suffixContext):
        if ctx.DOT():
            return (
                MemberAccess(ctx.ID().getText())
                if not ctx.method_call_args_opt()
                else MethodCall(
                    ctx.ID().getText(), self.visit(ctx.method_call_args_opt())
                )
            )
        return ArrayAccess(self.visit(ctx.expr()))

    def visitMethod_call_args_opt(self, ctx: OPLangParser.Method_call_args_optContext):
        return self.visit(ctx.arg_list())

    def visitArg_list(self, ctx: OPLangParser.Arg_listContext):
        return [] if ctx.getChildCount() == 0 else self.visit(ctx.arg_list_prime())

    def visitArg_list_prime(self, ctx: OPLangParser.Arg_list_primeContext):
        return (
            [self.visit(ctx.expr())]
            if ctx.getChildCount() == 1
            else [self.visit(ctx.expr())] + self.visit(ctx.arg_list_prime())
        )

    def visitClass_create_expr(self, ctx: OPLangParser.Class_create_exprContext):
        return ObjectCreation(ctx.ID().getText(), self.visit(ctx.arg_list()))

    def visitArray_expr(self, ctx: OPLangParser.Array_exprContext):
        return self.visit(ctx.expr_list())

    def visitExpr_list(self, ctx: OPLangParser.Expr_listContext):
        return [] if ctx.getChildCount() == 0 else self.visit(ctx.exprprime())

    def visitExprprime(self, ctx: OPLangParser.ExprprimeContext):
        return (
            [self.visit(ctx.expr())]
            if ctx.getChildCount() == 1
            else [self.visit(ctx.expr())] + self.visit(ctx.exprprime())
        )
