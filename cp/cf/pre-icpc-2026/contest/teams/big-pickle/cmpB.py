import subprocess
bad=0
for seed in range(1,400):
    inp=subprocess.run(['python3','genB1.py',str(seed)],capture_output=True,text=True).stdout
    if not inp.strip(): continue
    exp=subprocess.run(['./harnessB'],input=inp,capture_output=True,text=True).stdout.strip().split('\n')
    got=subprocess.run(['./B'],input=inp,capture_output=True,text=True).stdout.strip().split('\n')
    ans=[l.split()[1:] for l in exp if l.startswith('ANS')]
    if len(ans)!=len(got): print("seed",seed,"count",len(ans),len(got)); bad+=1; continue
    for a,b in zip(ans,got):
        bb=b.split()
        if a[0]=='-1':
            if bb[0]!='-1': print("seed",seed,"exp -1 got",bb); bad+=1
        else:
            if bb[0]=='-1': print("seed",seed,"exp set got -1",a); bad+=1
            elif not (set(map(int,a[1:]))-{0}) <= set(map(int,bb[1:])): print("seed",seed,"set",a,bb); bad+=1
        if bad>5: break
    if bad>5: break
print("B bad =",bad)
