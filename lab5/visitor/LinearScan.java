package visitor;
import java.util.*;

public class LinearScan {

	List<String> registers;
	HashMap<Integer, Alloc> map;
	List<LiveVar> active;
	List<LiveVar> liveInterval;
	Integer R;												// R = max allocatable registers
	Integer stack;
	Integer init;

	public LinearScan(Integer params,List<LiveVar> l,HashMap<Integer,Alloc> m,Integer s) {	// for params allocated s class registers for holding arguments
		liveInterval = l;
		map = m;
		init = s;
		stack = s;
		registers = new ArrayList<String>();
		for(int i=params;i<8;i++) registers.add("s"+i);
		for(int i=0;i<10;i++) registers.add("t"+i);
		R = 18-params;
	}

	public Integer linear_scan_register_allocation() {								// Assumes to be sorted [ Can sort if needed ]
		active = new ArrayList<LiveVar>();
		for(int i=0;i<liveInterval.size();i++) {
			expire_old_intervals(i);
			if(active.size() == R) {
				spill_at_interval(i);
			}
			else {
				Alloc allocation = new Alloc(registers.get(0));
				registers.remove(0);
				map.put(liveInterval.get(i).temp,allocation);
				int end = liveInterval.get(i).end;
				Integer j;
				for(j=0;j<active.size();j++) {
					if(active.get(j).end > end)
						break;
				}
				active.add(j,liveInterval.get(i));
			}
		}
		return (stack-init);
	}

	public void expire_old_intervals(int i) {
		int start = liveInterval.get(i).start;
		for(int j=0;j<active.size();j++) {
			if(active.get(j).end >= start)
				return;
			registers.add(map.get(active.get(j).temp).register);
			active.remove(j);
			j--; 																									// compansate the remove
		}
	}
	
	public void spill_at_interval(int i) {
		LiveVar spill = active.get(active.size()-1);
		Alloc allocation = new Alloc(stack++);
		if ( spill.end > liveInterval.get(i).end ) {
			map.put(liveInterval.get(i).temp,map.get(spill.temp));
			map.put(spill.temp, allocation);
			active.remove(spill);
			int end = liveInterval.get(i).end;
			Integer j;
			for(j=0;j<active.size();j++) {
				if(active.get(j).end > end)
					break;
			}
			active.add(j,liveInterval.get(i));
		} else {
			map.put(liveInterval.get(i).temp,allocation);
		}
	}

}

 
 
