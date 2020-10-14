#siv #primearry
import array
prime = array.array('i',[1] * 1000000 )
#print(prime[8])

#siv

def siv(n):
	prime[0] = 0
	#prime[1] = 0
	for i in range(4,n+1,2):
	
		prime[i] = 0
	for i in range(3, n+1, 2):
		if i*i > n:
			break

		if prime[i] == 1:
			for j in range(i*i, n+1, 2*i):
				prime[j] = 0
		


#printprime

def printprime(n):
	for i in range(n+1):
		if prime[i] == 1:
			print(i)
#main method

siv(1008)

t = int(input())


while t > 0:
	t -= 1
	n = int(input())
	printprime(n)
	print()

