/*
Read-only and write-only
Covariance and contravariance produce some interesting outcomes. Covariant types are read-only, while contravariant types are write-only.

Remember that covariant types accept subtypes, so ArrayList<? extends Number> can contain any object that is either of a Number type or its subtype.
*/
/*
In this example, line 9 works, because we can be certain that whatever we get from the ArrayList can be upcasted to a Number type (because if it extends Number, by definition, it is a Number).

But nums.add() doesn’t work, because we cannot be sure of the “actual type” of the object. All we know is that it must be a Number or its subtypes (e.g. Integer, Double, Long, etc.).

With contravariance, the converse is true.
*/


import java.util.ArrayList;

public class Main {
    public static void main(String args[]) {
        ArrayList<Integer> ints = new ArrayList<>();
        ArrayList<? super Integer> nums = ints;
        
        ints.add(new Integer(1)); // Ok
        nums.add(new Integer(2)); // Ok
        Integer n = nums.get(0); // Not ok
    }
}

/*
Line 9 works, because we can be certain that whatever the “actual type” of the object is, it must be Integer or its supertype, and thus accept an Integer object.

But line 10 doesn’t work, because we cannot be sure that we will get an Integer. For instance, nums could be referencing an ArrayList of Objects.
*/
