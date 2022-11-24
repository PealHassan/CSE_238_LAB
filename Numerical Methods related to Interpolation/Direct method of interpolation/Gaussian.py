



def isNeededPartialPivoting(Equation_Matrix,Number_of_Equation):

    for i in range(Number_of_Equation):
        Flag = False
        for j in range(Number_of_Equation):
            if(Equation_Matrix[j][i] == 0.0):
                Flag = True
            elif Flag == True:
                return Flag
    return False


def PartialPivoting(Equation_Matrix,Number_of_Equation):
    for i in range(Number_of_Equation-1):
        temp = abs(Equation_Matrix[i][i])
        row = i
        for j in range(i+1,Number_of_Equation):
            u = Equation_Matrix[j][i]
            if(abs(u) > temp):
                temp = abs(u)
                row = j

        if row != i:
            for j in range(Number_of_Equation+1):
                t = Equation_Matrix[row][j]
                Equation_Matrix[row][j] = Equation_Matrix[i][j]
                Equation_Matrix[i][j] = t
        for j in range(i+1,Number_of_Equation):
            if(Equation_Matrix[i][i] == 0.0):
                print('Math Error')
                return
            fact = (Equation_Matrix[j][i] / Equation_Matrix[i][i])
            for k in range(i,Number_of_Equation+1):
                Equation_Matrix[j][k] -= (fact * Equation_Matrix[i][k])

    ans = [0.0 for i in range(Number_of_Equation)]
    for i in range(Number_of_Equation - 1, -1, -1):
        if Equation_Matrix[i][i] == 0.0:
            print('Math Error.')
            return
        sum = 0.0
        for j in range(i + 1, Number_of_Equation):
            sum += (ans[j] * Equation_Matrix[i][j])
        sum = Equation_Matrix[i][Number_of_Equation] - sum
        ans[i] = sum / Equation_Matrix[i][i]
    return ans


def NaiveGaussianEliminationMethod(Equation_Matrix,Number_of_Equation):
    for i in range(Number_of_Equation-1):
        for j in range(i+1, Number_of_Equation):
            fact = (Equation_Matrix[j][i]/Equation_Matrix[i][i])
            for k in range(Number_of_Equation+1):
                Equation_Matrix[j][k] -= (fact*Equation_Matrix[i][k])

    ans = [0.0 for i in range(Number_of_Equation)]

    for i in range(Number_of_Equation-1,-1,-1):
        if Equation_Matrix[i][i] == 0.0:
            print('Math Error.')
            return
        sum = 0.0
        for j in range(i+1,Number_of_Equation):
            sum += (ans[j]*Equation_Matrix[i][j])
        sum = Equation_Matrix[i][Number_of_Equation] - sum
        ans[i] = sum/Equation_Matrix[i][i]
    return ans


def valid(Equation_Matrix,Number_of_Equation):

    for i in Equation_Matrix:
        if len(i) != (Number_of_Equation+1):
            return False
    return True


Error_Accept = 0.0000000001
def start(Eqn):
    Equation_Matrix = Eqn
    Number_of_Equation = len(Equation_Matrix)
    if valid(Equation_Matrix,Number_of_Equation) == False:
        print('Wrong Equation Given.')
    elif isNeededPartialPivoting(Equation_Matrix,Number_of_Equation):
        return PartialPivoting(Equation_Matrix,Number_of_Equation)
    else:
        return NaiveGaussianEliminationMethod(Equation_Matrix,Number_of_Equation)

    