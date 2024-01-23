import math

def main():
	pi = 3.141592653589793
	a,b,c,d = input().split()
	a,b,c,d = int(a),int(b),int(c),int(d)
	s1 = math.sqrt(a * a + b * b)
	s2 = math.sqrt(c * c + d * d)
	if s1 == 0 or s2 == 0:
		print('%.16f' % (s1 + s2))
		return
	#ss = (a * c + b * d) / (s1 * s2)
	l = math.fabs(math.atan2(b,a) - math.atan2(d,c))
	S = pi * min(s1, s2)

	S = S * (l / pi)
	x =  min(S + math.fabs(s1-s2), s1 + s2)
	print('%.16f' % x)

if __name__ == '__main__':
	main()