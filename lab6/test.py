import os
import glob

for fileName in glob.glob('miniRA/*.miniRA') :
	s = fileName.split('/')[1].split('.')[0]
	os.system('java P6 <'+fileName+' >MIPS/'+s+'.s')

for fileName in glob.glob('miniRA/*.miniRA') :
	s = fileName.split('/')[1].split('.')[0]
	os.system('java -jar kgi.jar <'+fileName+' >miniRA/output/'+s)

for fileName in glob.glob('MIPS/*.s') :
	s = fileName.split('/')[1].split('.')[0]
	os.system('spim -file '+fileName+' >MIPS/output/'+s)
	os.system('sed -i 1,5d MIPS/output/'+s)

for fileName in glob.glob('MIPS/output/*') :
	s = fileName.split('/')[2]
	print 'CASE : '+s
	print '--------------'
	os.system('colordiff '+fileName+' miniRA/output/'+s)
	print '--------------'