
def iniarr():
    l = ins().split(" ")
    for i in range(len(l)):
        l[i] = int(l[i])
    return l

def insarr():
    l = ins().split(" ")
    return l

def ini():
    return eval(ins())

def ins():
    return input()


def solve(cas):
    s = ins()
    ans = ""
    for i in s:
        if i>='A' and i<='Z':
            ans+=i
    print(ans)





if __name__ == "__main__":
    i = 1
    # i = ini()
    for i in range(i):
        solve(i)



# python main.py