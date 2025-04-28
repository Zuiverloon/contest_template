
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
    n = ini()
    arr = iniarr()
    ans = 0
    for i in range(0,n,2):
        ans+=arr[i]
    print(ans)





if __name__ == "__main__":
    i = 1
    # i = ini()
    for i in range(i):
        solve(i)



# python main.py