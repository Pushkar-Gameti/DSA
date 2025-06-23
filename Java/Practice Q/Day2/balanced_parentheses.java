import java.util.Stack;

public class Main {
    public static boolean isBalanced(String expr) {
        Stack<Character> s = new Stack<>();

        for (char ch : expr.toCharArray()) {
            if (ch == '(')
                s.push(ch);
            else if (ch == ')') {
                if (s.isEmpty())
                    return false;
                s.pop();
            }
        }

        return s.isEmpty();
    }

    public static void main(String[] args) {
        String expr = "((()))";
        System.out.println(isBalanced(expr) ? "Balanced" : "Not Balanced");
    }
}
