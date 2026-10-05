import subprocess, random, os, sys

def run(exe, inp):
    r = subprocess.run([exe], input=inp, capture_output=True, text=True, timeout=20)
    return r.stdout.strip()

random.seed(12345)
G = "./g_gen"
for trial in range(4000):
    n = random.randint(4, 14)
    mx = random.choice([2,3,4,5,8])
    inp = "1\n" + run(G, f"{n} {trial} {mx}\n")
    a = run("./g", inp)
    b = run("./g_brute", inp)
    if a != b:
        print("MISMATCH trial", trial, "n", n, "mx", mx)
        print("input:", inp.replace("\n"," "))
        print("fast:", a, "brute:", b)
        sys.exit(1)
print("all match (short)")
