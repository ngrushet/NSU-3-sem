
def fact(x): 
    
    return 

def teilor_cos(x,N):
    sum = 1
    sign = -1
    for i in range (1, N+1):
        sum += sign * pow(x,2*i) / fact(2 * i)  # teilor chain
        sign = - sign
    return sum


