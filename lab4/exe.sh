java P4 < $1 > exe.miniIR
cd microIR
java Main < ../exe.miniIR
cd ..
java -jar miniIR.jar <exe.miniIR >exeOut
java -jar miniIR.jar < $1 >exeIn
colordiff exeOut exeIn
rm exeIn
rm exeOut
 
