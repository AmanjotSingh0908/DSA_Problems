/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

var mergeTwoLists = function(list1, list2) {
    if (list1 === null) return list2;
    if (list2 === null) return list1;

    let dummy = new ListNode();
    let current = dummy;

    let curr1 = list1;
    let curr2 = list2;
    while (curr1 !== null && curr2 !== null) {
        if (curr1.val < curr2.val) {
            current.next = curr1;
            curr1 = curr1.next;
        } else {
            current.next = curr2;
            curr2 = curr2.next;
        }
        current = current.next;
    }

    if (curr1 !== null) {
        current.next = curr1;
    } else {
        current.next = curr2;
    }
    return dummy.next;
};
