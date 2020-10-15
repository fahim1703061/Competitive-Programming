#siv #primearry
import array
N = 100000002
#prime = array.array('i',[1]*N)
prime = [1]*N

#print(prime[10000000-1])
primelist = []


#siv

def siv(n):
	cnt = 0
	prime[0] = 0
	prime[1] = 0
	#primelist.append(2)
	#for i in range(4,n+1,2):
	
	#	prime[i] = 0
	for i in range(3, n+1, 2):
		if i*i > n:
			break

		if prime[i] == 1:
			#primelist.append(i)
			#cnt += 1
			for j in range(i*i, n+1, 2*i):
				prime[j] = 0
	

def printprime(n):
	cnt = 0
	j = 0
	i = 3
	primelist.append(2)
	while i < n+1:

		if j > 5000001 :
			break

		if prime[i] == 1:
			primelist.append(i)
			j +=1
			
		cnt += 1
		i += 2
	#print(cnt)
#main

siv(90000000)
#print("hei")
printprime(90000000)
#print("hei")
#print(primelist[5000000-4])
q = int(input())
while q > 0:
	q -= 1
	k = int(input())
	print(primelist[k-1])
#print(cnt)