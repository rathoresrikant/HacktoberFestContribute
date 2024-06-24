public class NthNodeFromLast {
	static class Node<T> {
		T value;
		Node<T> next;

		Node(T value) {
			this.value = value;
		}
	}

	static class LinkedList<T> {
		Node<T> root = null;
		Node<T> last = root;

		void add(T value) {
			Node<T> n = new Node<>(value);

			if (root == null) {
				root = n;
				last = root;
			} else {
				last.next = n;
				last = last.next;
			}
		}
	}

	private static <T> T nthNodeFromLast(LinkedList<T> list, int nth) {
		assert nth != 0;

		if (list == null) {
			return null;
		}

		Node<T> curr = list.root;

		int i = 0;
		// move the pointer to nth + 1 position
		while (i++ <= nth) {
			if (curr == null) {
				return null;
			}

			curr = curr.next;
		}

		// create new reference from the root which is nth distance away from curr pointer
		Node<T> target = list.root;

		// move curr pointer to the end of linked list, move the target pointer in sync
		while (curr != null) {
			curr = curr.next;
			target = target.next;
		}

		return target.value;
	}

	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList<>();
		list.add("A");
		list.add("B");
		list.add("C");
		list.add("D");

		System.out.println("D".equals(nthNodeFromLast(list, 0)));
		System.out.println("C".equals(nthNodeFromLast(list, 1)));
		System.out.println("B".equals(nthNodeFromLast(list, 2)));
		System.out.println("A".equals(nthNodeFromLast(list, 3)));
		System.out.println(null == nthNodeFromLast(list, 4));
	}
}