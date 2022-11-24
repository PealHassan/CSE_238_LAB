import Gaussian
import Quadratic


def Input():
    print("Warning: values of t should be in ascending order")
    x = [float(i) for i in input("Values of t: ").split()]
    y = [float(i) for i in input("Values of f(t): ").split()]
    z = float(input("Given t : "))
    return x, y, z

def Cubic(x,Fx,y,Fy,z,Fz,w,Fw,t):
    Eqn = []
    Eqn.append([1.0,x,x*x,x*x*x,Fx])
    Eqn.append([1.0,y,y*y,y*y*y,Fy])
    Eqn.append([1.0,z,z*z,z*z*z,Fz])
    Eqn.append([1.0,w,w*w,w*w*w,Fw])
    ans = Gaussian.start(Eqn)
    return ans[0] + (ans[1]*t) + (ans[2]*t*t) + (ans[3]*t*t*t)

def compare(ans,x,Fx,y,Fy,z,Fz,t):
    print("Comparison with respect to Quadratic : ",abs((ans - Quadratic.Quadratic(x,Fx,y,Fy,z,Fz,t))/ans)*100)


if __name__ == '__main__':
    x, y, z = Input()
    for i in range(1,len(x)):
        if x[i-1] <= z and z <= x[i]:
            ans = 0
            if(i-2 >= 0 and i+1 < len(x)):
                ans = Cubic(x[i-2],y[i-2],x[i-1],y[i-1],x[i],y[i],x[i+1],y[i+1],z)
                if abs(x[i-2]-z) < abs(x[i+1]-z): compare(ans,x[i-2],y[i-2],x[i-1],y[i-1],x[i],y[i],z)
                else: compare(ans,x[i-1],y[i-1],x[i],y[i],x[i+1],y[i+1],z)
            elif(i+2 < len(x)):
                ans = Cubic(x[i-1], y[i-1], x[i], y[i], x[i+1], y[i+1], x[i+2], y[i+2], z)
                compare(ans,x[i-1], y[i-1], x[i], y[i], x[i+1], y[i+1],z)
            else:
                ans = Cubic(x[i-2], y[i-2], x[i-1], y[i-1], x[i], y[i], x[i+1], y[i+1], z)
                compare(ans, x[i-1], y[i-1], x[i], y[i], x[i+1], y[i+1], z)

            print("Answer : ",ans)
            break