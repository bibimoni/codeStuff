class A:
    def show(self):
        print("A", end="")


class B(A):
    def show(self):
        super().show()
        print("B", end="")


class C(A):
    def show(self):
        print("C", end="")
        super().show()


class E(B, C):
    def show(self):
        print("E", end="")
        super().show()


E().show()
