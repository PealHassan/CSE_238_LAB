import Linear

def Input():
    print("Warning: values of t should be in ascending order")
    x = [float(i) for i in input("Values of t: ").split()]
    y = [float(i) for i in input("Values of f(t): ").split()]
    z = float(input("Given t : "))
    return x, y, z

def Quadratic(x,Fx,y,Fy,z,Fz,t):
    b0 = Fx
    b1 = (Fy-Fx)/(y-x)
    b2 = ((((Fz-Fy)/(z-y)) - b1) / (z-x))

    return b0 + (b1*(t-x)) + (b2*(t-y)*(t-x))

def compare(ans,x,Fx,y,Fy,t):
    print("Comaparison with respect to Linear : ",abs((ans-Linear.Linear(x,Fx,y,Fy,t))/ans)*100)


if __name__ == '__main__':
    x, y, z = Input()
    for i in range(1,len(x)):
        if x[i-1] <= z and z <= x[i]:
            ans = 0
            if(i-2 < 0):
                ans = Quadratic(x[i-1],y[i-1],x[i],y[i],x[i+1],y[i+1],z)
                compare(ans,x[i-1],y[i-1],x[i],y[i],z)
            elif i+1 >= len(x):
                ans = Quadratic(x[i-2],y[i-2],x[i-1],y[i-1],x[i],y[i],z)
                compare(ans,ans,x[i-1],y[i-1],x[i],y[i],z)
            else:
                if abs(z-x[i-2]) < abs(z-x[i+1]):
                    ans = Quadratic(x[i-2],y[i-2],x[i-1],y[i-1],x[i],y[i],z)
                    compare(ans,x[i-1],y[i-1],x[i],y[i],z)
                else:
                    ans = Quadratic(x[i-1],y[i-1],x[i],y[i],x[i+1],y[i+1],z)
                    compare(ans,ans,x[i-1],y[i-1],x[i],y[i],z)
            print("Answer : ",ans)
            break