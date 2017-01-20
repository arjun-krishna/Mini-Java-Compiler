import os
import glob

for fileName in glob.glob('microIR/*.microIR') :
	s = fileName.split('/')[1].split('.')[0]
	os.system('java P5 <'+fileName+' >miniRA/'+s+'.miniRA')

# for fileName in glob.glob('microIR/*') :
# 	s = fileName.split('/')[1].split('.')[0]
# 	os.system('java -jar miniIR.jar <'+fileName+' >microIR/output/'+s)

for fileName in glob.glob('miniRA/*.miniRA') :
	s = fileName.split('/')[1].split('.')[0]
	os.system('java -jar kgi.jar <'+fileName+' >miniRA/output/'+s)

for fileName in glob.glob('miniRA/output/*') :
	s = fileName.split('/')[2]
	print 'CASE : '+s
	print '--------------'
	os.system('colordiff '+fileName+' microIR/output/'+s)
	print '--------------'