
# bigmod
def bigmod(b_int, p_int, m_int):
    if p_int == 0:
        return 1
    if p_int == 1:
        return b_int % m_int
    if p_int % 2 == 1:
        return ((b_int % m_int) * (bigmod((((b_int % m_int) * (b_int % m_int)) % m_int), (p_int-1)/2, m_int) % m_int) % m_int)
    else:
        return bigmod((((b_int % m_int) * (b_int % m_int)) % m_int), (p_int)/2, m_int)


##t = input()
#t_int = int(t)
while True:
    try:
        b = input()
        if b == "":
            b = input()
        else:
            b = int(b)

        #b = input()
        
        p = input()
        m = input()
        b_inp = int(b)
        m_inp = int(m)
        p_inp = int(p)

    except EOFError:
        break

    print(bigmod(b_int=b_inp, p_int=p_inp, m_int=m_inp))

 