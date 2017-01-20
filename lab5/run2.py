import os
import glob

for fileName in glob.glob('microIR/others/*.microIR') :
	s = fileName.split('/')[2].split('.')[0]
	os.system('java P5 <'+fileName+' >miniRA/others/'+s+'.miniRA')

# for fileName in glob.glob('microIR/others/*.microIR') :
# 	s = fileName.split('/')[2].split('.')[0]
# 	print 'micro : '+s
# 	os.system('java -jar miniIR.jar <'+fileName+' >microIR/others/output/'+s)

for fileName in glob.glob('miniRA/others/*.miniRA') :
	s = fileName.split('/')[2].split('.')[0]
	print 'mini : '+s
	os.system('java -jar kgi.jar <'+fileName+' >miniRA/others/output/'+s)

for fileName in glob.glob('miniRA/others/output/*') :
	s = fileName.split('/')[3]
	print 'CASE : '+s
	print '--------------'
	os.system('colordiff '+fileName+' microIR/others/output/'+s)
	print '--------------'