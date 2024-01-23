n = int(input())

j = 1
l = 1
for i in range (n - 1 ):
	if l*l >j*j*j:
		j = j +1
	elif l*l == j*j*j :
		l+=1
		j+=1 
	else:
		l+=1


if l*l <j*j*j:
	print(l*l)
else:
	print(j*j*j)