# Generated from OPLang.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .OPLangParser import OPLangParser
else:
    from OPLangParser import OPLangParser

# This class defines a complete generic visitor for a parse tree produced by OPLangParser.

class OPLangVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by OPLangParser#program.
    def visitProgram(self, ctx:OPLangParser.ProgramContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#classlist.
    def visitClasslist(self, ctx:OPLangParser.ClasslistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#clas.
    def visitClas(self, ctx:OPLangParser.ClasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#members.
    def visitMembers(self, ctx:OPLangParser.MembersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#member.
    def visitMember(self, ctx:OPLangParser.MemberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#attributedecl.
    def visitAttributedecl(self, ctx:OPLangParser.AttributedeclContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#attributelist.
    def visitAttributelist(self, ctx:OPLangParser.AttributelistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#attribute.
    def visitAttribute(self, ctx:OPLangParser.AttributeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#attrmods.
    def visitAttrmods(self, ctx:OPLangParser.AttrmodsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#methoddecl.
    def visitMethoddecl(self, ctx:OPLangParser.MethoddeclContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#paramlist.
    def visitParamlist(self, ctx:OPLangParser.ParamlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#paramprime.
    def visitParamprime(self, ctx:OPLangParser.ParamprimeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#param.
    def visitParam(self, ctx:OPLangParser.ParamContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#idlist.
    def visitIdlist(self, ctx:OPLangParser.IdlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#stmtlist.
    def visitStmtlist(self, ctx:OPLangParser.StmtlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#stmt.
    def visitStmt(self, ctx:OPLangParser.StmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#blockstmt.
    def visitBlockstmt(self, ctx:OPLangParser.BlockstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#vardecl.
    def visitVardecl(self, ctx:OPLangParser.VardeclContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#varlist.
    def visitVarlist(self, ctx:OPLangParser.VarlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#varitem.
    def visitVaritem(self, ctx:OPLangParser.VaritemContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#varlist2.
    def visitVarlist2(self, ctx:OPLangParser.Varlist2Context):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#varitem2.
    def visitVaritem2(self, ctx:OPLangParser.Varitem2Context):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#assignstmt.
    def visitAssignstmt(self, ctx:OPLangParser.AssignstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#assignlist.
    def visitAssignlist(self, ctx:OPLangParser.AssignlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#assignonce.
    def visitAssignonce(self, ctx:OPLangParser.AssignonceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#ifstmt.
    def visitIfstmt(self, ctx:OPLangParser.IfstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#forstmt.
    def visitForstmt(self, ctx:OPLangParser.ForstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#breakstmt.
    def visitBreakstmt(self, ctx:OPLangParser.BreakstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#continuestmt.
    def visitContinuestmt(self, ctx:OPLangParser.ContinuestmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#returnstmt.
    def visitReturnstmt(self, ctx:OPLangParser.ReturnstmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#methodinvokestmt.
    def visitMethodinvokestmt(self, ctx:OPLangParser.MethodinvokestmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#type.
    def visitType(self, ctx:OPLangParser.TypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#typevoid.
    def visitTypevoid(self, ctx:OPLangParser.TypevoidContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#type_array_suff.
    def visitType_array_suff(self, ctx:OPLangParser.Type_array_suffContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#base_type.
    def visitBase_type(self, ctx:OPLangParser.Base_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#constructor.
    def visitConstructor(self, ctx:OPLangParser.ConstructorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#destructor.
    def visitDestructor(self, ctx:OPLangParser.DestructorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#expr.
    def visitExpr(self, ctx:OPLangParser.ExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#relational_expr.
    def visitRelational_expr(self, ctx:OPLangParser.Relational_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#relational_expr_tail.
    def visitRelational_expr_tail(self, ctx:OPLangParser.Relational_expr_tailContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#eq_expr.
    def visitEq_expr(self, ctx:OPLangParser.Eq_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#eq_expr_tail.
    def visitEq_expr_tail(self, ctx:OPLangParser.Eq_expr_tailContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#orand_expr.
    def visitOrand_expr(self, ctx:OPLangParser.Orand_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#addsub_expr.
    def visitAddsub_expr(self, ctx:OPLangParser.Addsub_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#muldiv_expr.
    def visitMuldiv_expr(self, ctx:OPLangParser.Muldiv_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#caret_expr.
    def visitCaret_expr(self, ctx:OPLangParser.Caret_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#unary_expr.
    def visitUnary_expr(self, ctx:OPLangParser.Unary_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#post_expr.
    def visitPost_expr(self, ctx:OPLangParser.Post_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#post_expr_tail.
    def visitPost_expr_tail(self, ctx:OPLangParser.Post_expr_tailContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#post_suffix.
    def visitPost_suffix(self, ctx:OPLangParser.Post_suffixContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#method_call_args_opt.
    def visitMethod_call_args_opt(self, ctx:OPLangParser.Method_call_args_optContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#primary.
    def visitPrimary(self, ctx:OPLangParser.PrimaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#class_create_expr.
    def visitClass_create_expr(self, ctx:OPLangParser.Class_create_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#arg_list.
    def visitArg_list(self, ctx:OPLangParser.Arg_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#arg_list_prime.
    def visitArg_list_prime(self, ctx:OPLangParser.Arg_list_primeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#array_access.
    def visitArray_access(self, ctx:OPLangParser.Array_accessContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#array_expr.
    def visitArray_expr(self, ctx:OPLangParser.Array_exprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#expr_list.
    def visitExpr_list(self, ctx:OPLangParser.Expr_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by OPLangParser#exprprime.
    def visitExprprime(self, ctx:OPLangParser.ExprprimeContext):
        return self.visitChildren(ctx)



del OPLangParser