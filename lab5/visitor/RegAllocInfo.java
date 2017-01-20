package visitor;
import java.util.*;

public class RegAllocInfo {
	public HashMap<String,Integer> maxCallArgSize;
	public HashMap<String,HashMap<Integer,Alloc>> regAlloc;
	public HashMap<String,Integer> stackAlloc;		
	
	public RegAllocInfo() {
		maxCallArgSize = new HashMap<String,Integer>();
		regAlloc = new HashMap<String,HashMap<Integer,Alloc>>();
		stackAlloc = new HashMap<String,Integer>();
	}

	public void debug() {
		System.out.println(" -- RegAllocInfo -- ");
		System.out.println("____________________");
		System.out.println("maxCallArgSize : ");
		System.out.println(maxCallArgSize);
		System.out.println("____________________");
		System.out.println("stackAlloc : ");
		System.out.println(stackAlloc);
		System.out.println("____________________");
		System.out.println("regAlloc : ");
		System.out.println(regAlloc);
		System.out.println("____________________");
	}
}

class Alloc {												// change the attribs
	Integer spill;
	String register;
	boolean isReg;									// true if Register						

	public Alloc(Integer s) {
		isReg = false;
		spill = s;
		register = null;
	}

	public Alloc(String r) {
		isReg = true;
		register = r;
		spill = null;
	}

	public String toString() {
		return (isReg)? register : ("S-"+spill);
	}
}