//
// Generated by JTB 1.3.2
//

package visitor;
import syntaxtree.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class PrintMIPS<R,A> implements GJVisitor<R,A> {
   //
   // Auto class visitors--probably don't need to be overridden.
   //

  String funcHeader = "\t.text\n\t.globl\t";
  Integer args = 0;

  public void printSysCalls() {
    String defaultStr = ""+
    // HALLOC CODE 
           "\t.text\n"+
           "\t.globl _halloc\n"+
    "_halloc:\n"+
             "\tli $v0, 9\n"+
             "\tsyscall\n"+
             "\tjr $ra\n\n"+
  
    // PRINT CODE [ use to print integers ]
             "\t.text\n"+
             "\t.globl _print\n"+
    "_print:\n"+
             "\tli $v0, 1\n"+
             "\tsyscall\n"+
             "\tla $a0, newl\n"+
             "\tli $v0, 4\n"+
             "\tsyscall\n"+
             "\tjr $ra\n\n"+
    
    // ERROR CODE 
             "\t.text\n"+
             "\t.globl _error\n"+
    "_error:\n"+
             "\tla $a0, err_msg\n"+
             "\tli $v0, 4\n"+
             "\tsyscall\n"+
             "\tli $v0, 10\n"+
             "\tsyscall\n\n"+                         // EXIT

    // DATA SECTION 
             "\t.data\n"+
             "\t.align   0\n"+
    "newl:   .asciiz \"\\n\"\n"+ 
             "\t.data\n"+
             "\t.align   0\n"+
    "str_er: .asciiz \" ERROR: abnormal termination\\n\"\n"+
             "\t.data\n"+
             "\t.align   0\n"+
    "err_msg:.asciiz \"ERROR\\n\"\n\n";    

    System.out.println(defaultStr);
  }

   public R visit(NodeList n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeListOptional n, A argu) {
      if ( n.present() ) {
         R _ret=null;
         int _count=0;
         for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this,argu);
            _count++;
         }
         return _ret;
      }
      else
         return null;
   }

   public R visit(NodeOptional n, A argu) {
      if ( n.present() ) {
         String l =  (String) n.node.accept(this,argu);
         System.out.print(l+":");
         return (R)l;
      }
      else
         return null;
   }

   public R visit(NodeSequence n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeToken n, A argu) { return null; }

   //
   // User-generated visitor methods below
   //

   /**
    * f0 -> "MAIN"
    * f1 -> "["
    * f2 -> IntegerLiteral()
    * f3 -> "]"
    * f4 -> "["
    * f5 -> IntegerLiteral()
    * f6 -> "]"
    * f7 -> "["
    * f8 -> IntegerLiteral()
    * f9 -> "]"
    * f10 -> StmtList()
    * f11 -> "END"
    * f12 -> ( Procedure() )*
    * f13 -> VariablePackingInfo()
    * f14 -> <EOF>
    */
   public R visit(Goal n, A argu) {
      R _ret=null;
      System.out.println(funcHeader+"main");
      System.out.println("main:");
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      args = (Integer) n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      Integer stackSlots = (Integer) n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      n.f7.accept(this, argu);
      Integer maxCallArg = (Integer) n.f8.accept(this, argu);
      n.f9.accept(this, argu);
      
      Integer stack = 8 + (stackSlots)*4 + ((maxCallArg > 4 ) ? (maxCallArg-4)*4 : 0);
      System.out.println("\tsw $fp, -8($sp)");
      System.out.println("\tmove $fp, $sp");
      System.out.println("\tsubu $sp, $sp, "+stack);
      System.out.println("\tsw $ra, -4($fp)");

      n.f10.accept(this, argu);

      System.out.println("\tlw $ra, -4($fp)");
      System.out.println("\tlw $fp, -8($fp)");
      System.out.println("\taddu $sp, $sp, "+stack);
      System.out.println("\tjr $ra");
      n.f11.accept(this, argu);
      System.out.println();                   // add for readability
      n.f12.accept(this, argu);
      n.f13.accept(this, argu);
      n.f14.accept(this, argu);
      printSysCalls();
      return _ret;
   }

   /**
    * f0 -> ( ( Label() )? Stmt() )*
    */
   public R visit(StmtList n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Label()
    * f1 -> "["
    * f2 -> IntegerLiteral()
    * f3 -> "]"
    * f4 -> "["
    * f5 -> IntegerLiteral()
    * f6 -> "]"
    * f7 -> "["
    * f8 -> IntegerLiteral()
    * f9 -> "]"
    * f10 -> StmtList()
    * f11 -> "END"
    */
   public R visit(Procedure n, A argu) {
      R _ret=null;
      String function = (String) n.f0.accept(this, argu);
      System.out.println(funcHeader+function);
      System.out.println(function+":");
      n.f1.accept(this, argu);
      args = (Integer) n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      Integer stackSlots = (Integer) n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      n.f7.accept(this, argu);
      Integer maxCallArg = (Integer) n.f8.accept(this, argu);
      n.f9.accept(this, argu);

      Integer stack = 8 + (stackSlots)*4 + ((maxCallArg > 4 ) ? (maxCallArg-4)*4 : 0);
      System.out.println("\tsw $fp, -8($sp)");
      System.out.println("\tmove $fp, $sp");
      System.out.println("\tsubu $sp, $sp, "+stack);
      System.out.println("\tsw $ra, -4($fp)");

      n.f10.accept(this, argu);

      System.out.println("\tlw $ra, -4($fp)");
      System.out.println("\tlw $fp, -8($fp)");
      System.out.println("\taddu $sp, $sp, "+stack);
      System.out.println("\tjr $ra");
      
      n.f11.accept(this, argu);
      System.out.println();                   // add for readability
      return _ret;
   }

   /**
    * f0 -> NoOpStmt()
    *       | ErrorStmt()
    *       | CJumpStmt()
    *       | JumpStmt()
    *       | HStoreStmt()
    *       | HLoadStmt()
    *       | MoveStmt()
    *       | PrintStmt()
    *       | ALoadStmt()
    *       | AStoreStmt()
    *       | PassArgStmt()
    *       | CallStmt()
    */
   public R visit(Stmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "NOOP"
    */
   public R visit(NoOpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      System.out.println("\tnop");
      return _ret;
   }

   /**
    * f0 -> "ERROR"
    */
   public R visit(ErrorStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      System.out.println("\tjal _error");
      return _ret;
   }

   /**
    * f0 -> "CJUMP"
    * f1 -> Reg()
    * f2 -> Label()
    */
   public R visit(CJumpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String reg = (String) n.f1.accept(this, argu);
      String target = (String) n.f2.accept(this, argu);
      System.out.println("\tbne "+reg+", 1, "+target);
      return _ret;
   }

   /**
    * f0 -> "JUMP"
    * f1 -> Label()
    */
   public R visit(JumpStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String target = (String) n.f1.accept(this, argu);
      System.out.println("\tj "+target);
      return _ret;
   }

   /**
    * f0 -> "HSTORE"
    * f1 -> Reg()
    * f2 -> IntegerLiteral()
    * f3 -> Reg()
    */
   public R visit(HStoreStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String addr = (String) n.f1.accept(this, argu);
      Integer offset = (Integer) n.f2.accept(this, argu);
      String reg = (String) n.f3.accept(this, argu);
      System.out.println("\tsw "+reg+", "+offset+"("+addr+")");
      return _ret;
   }

   /**
    * f0 -> "HLOAD"
    * f1 -> Reg()
    * f2 -> Reg()
    * f3 -> IntegerLiteral()
    */
   public R visit(HLoadStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String reg = (String) n.f1.accept(this, argu);
      String addr = (String) n.f2.accept(this, argu);
      Integer offset = (Integer) n.f3.accept(this, argu);
      System.out.println("\tlw "+reg+", "+offset+"("+addr+")");
      return _ret;
   }

   /**
    * f0 -> "MOVE"
    * f1 -> Reg()
    * f2 -> Exp()
    */
   public R visit(MoveStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String reg = (String) n.f1.accept(this, argu);
      argu = (A) reg;
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "PRINT"
    * f1 -> SimpleExp()
    */
   public R visit(PrintStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      SE simpleExp = (SE) n.f1.accept(this, argu);
      switch(simpleExp.type) {
        case 0 : {
          System.out.println("\tmove $a0, "+simpleExp);
          break;
        }
        case 1 : {
          System.out.println("\tli $a0, "+simpleExp);
          break;
        }
        // need not handle label case(2) -- Should not occur        
      }
      System.out.println("\tjal _print");
      return _ret;
   }

   /**
    * f0 -> "ALOAD"
    * f1 -> Reg()
    * f2 -> SpilledArg()
    */
   public R visit(ALoadStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      String reg = (String) n.f1.accept(this, argu);
      Integer stack = (Integer) n.f2.accept(this, argu);
      if((args > 4) && (stack < (args-4)))
        System.out.println("\tlw "+reg+", "+(stack*4)+"($fp)");
      else
        System.out.println("\tlw "+reg+", "+(stack*4)+"($sp)");
      return _ret;
   }

   /**
    * f0 -> "ASTORE"
    * f1 -> SpilledArg()
    * f2 -> Reg()
    */
   public R visit(AStoreStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      Integer stack = (Integer) n.f1.accept(this, argu);
      String reg = (String) n.f2.accept(this, argu);
      if((args > 4) && (stack < (args-4)))
        System.out.println("\tsw "+reg+", "+(stack*4)+"($fp)");
      else
        System.out.println("\tsw "+reg+", "+(stack*4)+"($sp)");
      return _ret;
   }

   /**
    * f0 -> "PASSARG"
    * f1 -> IntegerLiteral()
    * f2 -> Reg()
    */
   public R visit(PassArgStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      Integer stack = (Integer) n.f1.accept(this, argu);
      String reg = (String) n.f2.accept(this, argu);
      System.out.println("\tsw "+reg+", "+((stack-1)*4)+"($sp)");
      return _ret;
   }

   /**
    * f0 -> "CALL"
    * f1 -> SimpleExp()
    */
   public R visit(CallStmt n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      SE simpleExp = (SE) n.f1.accept(this, argu);
      switch(simpleExp.type) {
        case 0 : {
          System.out.println("\tjalr "+simpleExp);
          break;
        }
        case 2 : {
          System.out.println("\tjal "+simpleExp);
          break;
        }
        // integer simpleExp cannot happen [ case(1) -- doesn't occur ]
      }
      return _ret;
   }

   /**
    * f0 -> HAllocate()
    *       | BinOp()
    *       | SimpleExp()
    */
   public R visit(Exp n, A argu) {
      R _ret=null;
      String reg = (String) argu;
      SE exp  =  (SE) n.f0.accept(this, argu);
      if (n.f0.which != 1) {
        switch(exp.type) {
          case 0 : {  //reg
            System.out.println("\tmove "+reg+", "+exp);
            break;
          }
          case 1 : { // int
            System.out.println("\tli "+reg+", "+exp);
            break;
          }
          case 2 : { // label
            System.out.println("\tla "+reg+", "+exp);
          }
        }
      }
      return _ret;
   }

   /**
    * f0 -> "HALLOCATE"
    * f1 -> SimpleExp()
    */
   public R visit(HAllocate n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      SE exp = (SE) n.f1.accept(this, argu);
      switch(exp.type) {
        case 0 : { // reg
          System.out.println("\tmove $a0, "+exp);
          break;
        }
        case 1 : { // int
          System.out.println("\tli $a0, "+exp);
          break;
        }
        // label shouldn't occur [case(2) doesn't happen]
      }
      System.out.println("\tjal _halloc");
      SE ret = new SE<R>(0,(R)"$v0");
      
      _ret = (R) ret;
      return _ret;
   }

   /**
    * f0 -> Operator()
    * f1 -> Reg()
    * f2 -> SimpleExp()
    */
   public R visit(BinOp n, A argu) {
      R _ret=null;
      String rdest = (String) argu;
      String op = (String) n.f0.accept(this, argu);
      String r1 = (String) n.f1.accept(this, argu);
      SE r2 = (SE) n.f2.accept(this, argu); 
      
      if(op.equals("LT")) {
        System.out.println("\tslt "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("PLUS")) {
        System.out.println("\tadd "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("MINUS")) {
        System.out.println("\tsub "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("TIMES")) {
        System.out.println("\tmul "+rdest+", "+r1+", "+r2); 
      }
      if(op.equals("DIV")) {
        System.out.println("\tdiv "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("BITOR")) {
        System.out.println("\tor "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("BITAND")) {
        System.out.println("\tand "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("LSHIFT")) {
        System.out.println("\tsll "+rdest+", "+r1+", "+r2); 
      }
      if(op.equals("RSHIFT")) {
        System.out.println("\tsrl "+rdest+", "+r1+", "+r2);
      }
      if(op.equals("BITXOR")) {
        System.out.println("\txor "+rdest+", "+r1+", "+r2);
      }
      return _ret;
   }

   /**
    * f0 -> "LT"
    *       | "PLUS"
    *       | "MINUS"
    *       | "TIMES"
    *       | "DIV"
    *       | "BITOR"
    *       | "BITAND"
    *       | "LSHIFT"
    *       | "RSHIFT"
    *       | "BITXOR"
    */
   public R visit(Operator n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      switch(n.f0.which) {
        case 0 : return (R) "LT";
        case 1 : return (R) "PLUS";
        case 2 : return (R) "MINUS";
        case 3 : return (R) "TIMES";
        case 4 : return (R) "DIV";
        case 5 : return (R) "BITOR";
        case 6 : return (R) "BITAND";
        case 7 : return (R) "LSHIFT";
        case 8 : return (R) "RSHIFT";
        case 9 : return (R) "BITXOR";
      }
      return _ret;
   }

   /**
    * f0 -> "SPILLEDARG"
    * f1 -> IntegerLiteral()
    */
   public R visit(SpilledArg n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      _ret = n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Reg()
    *       | IntegerLiteral()
    *       | Label()
    */
   public R visit(SimpleExp n, A argu) {
      R _ret=null;
      _ret = n.f0.accept(this, argu);
      SE temp =  new SE<R>(n.f0.which,_ret);
      _ret = (R) temp;
      return _ret;
   }

   /**
    * f0 -> "a0"
    *       | "a1"
    *       | "a2"
    *       | "a3"
    *       | "t0"
    *       | "t1"
    *       | "t2"
    *       | "t3"
    *       | "t4"
    *       | "t5"
    *       | "t6"
    *       | "t7"
    *       | "s0"
    *       | "s1"
    *       | "s2"
    *       | "s3"
    *       | "s4"
    *       | "s5"
    *       | "s6"
    *       | "s7"
    *       | "t8"
    *       | "t9"
    *       | "v0"
    *       | "v1"
    */
   public R visit(Reg n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      switch(n.f0.which) {
        case 0  : _ret = (R) "$a0"; break;
        case 1  : _ret = (R) "$a1"; break;
        case 2  : _ret = (R) "$a2"; break;
        case 3  : _ret = (R) "$a3"; break;
        case 4  : _ret = (R) "$t0"; break;
        case 5  : _ret = (R) "$t1"; break;
        case 6  : _ret = (R) "$t2"; break;
        case 7  : _ret = (R) "$t3"; break;
        case 8  : _ret = (R) "$t4"; break;
        case 9  : _ret = (R) "$t5"; break;
        case 10 : _ret = (R) "$t6"; break;
        case 11 : _ret = (R) "$t7"; break;
        case 12 : _ret = (R) "$s0"; break;
        case 13 : _ret = (R) "$s1"; break;
        case 14 : _ret = (R) "$s2"; break;
        case 15 : _ret = (R) "$s3"; break;
        case 16 : _ret = (R) "$s4"; break;
        case 17 : _ret = (R) "$s5"; break;
        case 18 : _ret = (R) "$s6"; break;
        case 19 : _ret = (R) "$s7"; break;
        case 20 : _ret = (R) "$t8"; break;
        case 21 : _ret = (R) "$t9"; break;
        case 22 : _ret = (R) "$v0"; break;
        case 23 : _ret = (R) "$v1"; break;
      }
      return _ret;
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    */
   public R visit(IntegerLiteral n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      _ret = (R) (Integer) Integer.parseInt(n.f0.toString());
      return _ret;
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public R visit(Label n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      _ret = (R) n.f0.toString();
      return _ret;
   }

   /**
    * f0 -> "// Number of  vars after packing ="
    * f1 -> IntegerLiteral()
    * f2 -> "; Number of Spilled vars ="
    * f3 -> IntegerLiteral()
    */
   public R visit(VariablePackingInfo n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      n.f3.accept(this, argu);
      return _ret;
   }

}

class SE<R> {
  public int type;  // 0 - Reg, 1 - Integer Literal , 2- Label
  public R var;

  public SE(int t,R v) {
    type = t;
    var = v;
  }

  public String toString() {
    switch(type) {
      case 0 : {
        return (String) var;
      }
      case 1 : {
        return String.valueOf((Integer)var);
      }
      case 2 : {
        return (String) var;
      }
    }
    return "";
  }

}