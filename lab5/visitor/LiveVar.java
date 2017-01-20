package visitor;
import java.util.*;

public class LiveVar implements Comparable<LiveVar> {
	int temp,start,end;

	public LiveVar(Integer t,Integer s,Integer e) {
		// constructor
		temp = t;
		start = s;
		end = e;
	}

	public int compareTo(LiveVar var) {
		if ( start < var.start ) {					// starts before var
			return -1;
		}
		else if ( start == var.start ) {
			if ( end < var.end ) {						// starts with var and terminates before it
				return -1;	
			} else if ( end > var.end ) {			// starts with var and terminates after it
				return 1;
			} else {													// same interval
				return 0;
			}
		}
		else {															// starts after var
			return 1;													
		}
	}	
}