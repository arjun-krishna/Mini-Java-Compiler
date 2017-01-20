package visitor;
import java.util.*;

public class LiveInfo {

	public HashMap <Integer, Set<Integer> > succ;											// store a statement number's corresponding successor numbers
	public HashMap <Integer, Set<Integer> > in;												// Live in temp numbers for a statement number 
	public HashMap <Integer, Set<Integer> > out;											// Live out temp numbers for a statement number
	public HashMap <Integer, Set<Integer> > def;											// def temp numbers at statement number 
	public HashMap <Integer, Set<Integer> > use;											// use temp numbers at statement number

	public LiveInfo() {

		succ = new HashMap <Integer, Set<Integer> > ();
		in = new HashMap <Integer, Set<Integer> > ();
		out = new HashMap <Integer, Set<Integer> >();
		def = new HashMap <Integer, Set<Integer> > ();
		use = new HashMap <Integer, Set<Integer> > ();
	}

	public void debug() {

		System.out.println("statement, DEF, USE, SUCCESSOR");
		for (Map.Entry<Integer,Set<Integer>> entry : def.entrySet()) {
    	Integer key = entry.getKey();
    	Set<Integer> value = entry.getValue();
    	System.out.println(key+" , "+value+" , "+use.get(key)+" , "+succ.get(key));
		}
	}

	public void livelinessAnalysis(int start,int end) {

		for(int i=start;i<=end;i++) {
      Set<Integer> inTemp = new HashSet<Integer>();
      Set<Integer> outTemp = new HashSet<Integer>();
      in.put(i,inTemp);
      out.put(i,outTemp);
    }
    int changeIn,changeOut;
    do {
      changeIn = 0;
      changeOut = 0;
      for(int i=start;i<=end;i++) {
        changeIn += in.get(i).size();
        changeOut += out.get(i).size();
        // in[n] = use[n] + ( out[n] - def[n])
        Set<Integer> s = new HashSet<Integer>(out.get(i));
        s.removeAll(def.get(i));
        s.addAll(use.get(i));
        in.put(i,s);
        // out[n] = U(succ) { in[n] }
        s = new HashSet<Integer>();
        for(Integer successor: succ.get(i)) {
          if(successor != 0) {
            s.addAll(in.get(successor));
          }
        }
        out.put(i,s);
        changeIn -= in.get(i).size();
        changeOut -= out.get(i).size();
      }
    } while(changeIn != 0 || changeOut != 0);
	}

}