import math

def main():
	a = []
	d = input()
	for i in d:
		if i in "({[":
			a.append(i)
		else:
			if a == []:
				return "no"
			if i == ')' and a[-1] == '(':
				a.pop()
				continue
			if i == ']' and a[-1] == '[':
				a.pop()
				continue
			if i == '}' and a[-1] == '{':
				a.pop()
				continue
			return "no"
	if a == []:
		return "yes"
	return "no"

if __name__ == '__main__':
	print(main())