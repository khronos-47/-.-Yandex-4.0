import math

def main():

	n = int(input())
	k = int(input())
	s = [0]
	for i in range(1,k +1):
		s.append(int(input()))
	sum = 0

	for i in range(k,0,-1):
		sum = sum + (s[i] // n) * (i * 2)
		if s[i] % n !=0:
			sum = sum + 2
		s[i-1] = s[i - 1] +  s[i] % n
	print(int(sum))
if __name__ == '__main__':
	main()