# bigmod
def bigmod(b_int, p_int, m_int):  #b^p % m
    if p_int == 0:
        return 1
    if p_int == 1:
        return b_int % m_int
    if p_int % 2 == 1:
        return ((b_int % m_int) * (bigmod((((b_int % m_int) * (b_int % m_int)) % m_int), (p_int-1)/2, m_int) % m_int) % m_int)
    else:
        return bigmod((((b_int % m_int) * (b_int % m_int)) % m_int), (p_int)/2, m_int)




def summ(sn,pn,m_int) :
    return (sn % m_int + pn % m_int) % m_int

def multiply(a, b, m_int) :
    return((a % m_int) * (b % m_int)) % m_int


#taking input #program starts

#print(-20 % 10)

while True :
    #n = input()
    #k = input()

    #n = int(n)
    #k = int(k)
    n,k = map(int,input().split())

    #print(n,k)

    if n == 0 and k == 0 :
        break
    mod = 10000007
    
    output = summ(bigmod(n, n, mod), bigmod(n, k, mod), mod)
    add = multiply(2, bigmod(n-1, n-1, mod), mod)
    output = summ(output, add, mod)
    add = multiply(2, bigmod(n-1, k, mod), mod)
    output = summ(output, add, mod)
    
    print(output)




    
