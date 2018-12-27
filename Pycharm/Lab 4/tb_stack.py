from stack import stack

testvals = [ 1,100,10000,2000,20000,30000 ]
x=stack()

for i in testvals:
   x.push(i)

for i in range(len(testvals)-1,-1,-1):
   x.disp()
   r=x.pop()
   g=testvals[i]
   if r != g:
      print "ERR: expected:",g,"got:",r
