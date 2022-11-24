def Input():
    n = int(input("Number of points : "))
    dat = [float(i) for i in input("Points are :\n").split()]
    x,y = [],[]
    for i in range(0,2*n,2):
        x.append(dat[i])
        y.append(dat[i+1])
    return n,x,y

def RegressionModel(n,xpoints, ypoints):
    xmean = 0.0
    ymean = 0.0
    for i in range(n):
        xmean+=xpoints[i]
        ymean+=ypoints[i]
    xmean /= n
    ymean /= n
    up,down = 0.0,0.0
    for i in range(n):
        down += ((xpoints[i]-xmean)*(xpoints[i]-xmean))
        up += ((ypoints[i]-ymean)*(xpoints[i]-xmean))

    b1 = up/down
    b0 = ymean - (b1*xmean)
    print(f"y = {(b0)} + ({b1})*x")



if __name__ == '__main__':
    n,xpoints, ypoints = Input()
    RegressionModel(n,xpoints,ypoints)
