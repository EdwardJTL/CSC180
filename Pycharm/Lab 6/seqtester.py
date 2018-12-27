from seqdetectorlib import *

words_list = ["here", "the", "solutions","are", "the", "solutions", "here", "are", "solutions","here", "are","the", "solutions","to", "the", "next", "exam"]
x=seqdetector()
n=0


for i in words_list:
   status=x.evolve(i)
   if status == True:
      print "Detected: end position is",n
   n = n+1