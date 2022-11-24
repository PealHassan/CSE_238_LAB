import Gaussian

def Input():
    print("Warning: values of t should be in ascending order")
    x = [float(i) for i in input("Values of t: ").split()]
    y = [float(i) for i in input("Values of f(t): ").split()]
    z = float(input("Given t : "))
    return x, y, z

def Linear(x,Fx,y,Fy,t):
    Eqn = []
    Eqn.append([1.0,x,Fx])
    Eqn.append([1.0,y,Fy])
    ans = Gaussian.start(Eqn)
    return ans[0] + (ans[1]*t)




if __name__ == '__main__':
    x, y, z = Input()
    for i in range(1,len(x)):
        if x[i-1] <= z and z <= x[i]:
            print("Answer : ",Linear(x[i-1],y[i-1],x[i],y[i],z))
            break



# 0 10 15 20 22.5 30
# 0 227.04 362.78 517.35 602.97 901.67
# 16

