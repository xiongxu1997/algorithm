#include <cstring>
#include <vector>
using namespace std;
//
// Created by xx on 2023/3/24.
//
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// 链表的所有操作
class Solution {
public:
    // 反转链表
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr || pHead->next==nullptr) {
            return pHead;
        }
        ListNode* last = nullptr;
        ListNode* cur = pHead;
        // 头插法
        while(cur){
            ListNode* next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }

    // 将链表的第m到第n个位置的元素进行反转
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 设置一个表头
        ListNode* before_head = new ListNode(-1);
        before_head->next = head;
        // 移动last指针，使cur定位到第m个节点
        ListNode* last = before_head;
        ListNode* cur = nullptr;
        for(int i=0;i<m-1;i++){
            last = last->next;
        }
        cur = last->next;
        // 开始n-m次反转
        for(int i=0;i<n-m;i++){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = last->next;
            last->next = next;
        }
        return before_head->next;
    }

    // 合并两个已排好序的链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(pHead1!=nullptr and pHead2!=nullptr){
            if(pHead1->val < pHead2->val){
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if(pHead1==nullptr){
            cur->next = pHead2;
        }else{
            cur->next = pHead1;
        }
        return head->next;
    }

    // 合并k个已排序链表
    ListNode* divideMerge(vector<ListNode *> &lists, int left, int right) {
        if(left > right){
            return nullptr;
        }else if(left == right){
            return lists[left];
        }
        int mid = (left+right)/2;
        return Merge(divideMerge(lists, left, mid), divideMerge(lists, mid+1, right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideMerge(lists, 0, lists.size()-1);
    }

    // 判断链表中是否存在环
    bool hasCycle(ListNode *head) {
        ListNode* low = head;
        ListNode* fast = head;
        while(fast and fast->next){
            fast = fast->next->next;
            low = low->next;
            if(fast==low)
                return true;
        }
        return false;
    }

    // 链表中环的入口节点
    ListNode* EntryNodeOfLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(fast==nullptr or fast->next==nullptr){
            return nullptr;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    // 输出链表倒数第k个节点
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        for(int i=0;i<k;i++){
            if(fast){
                fast = fast->next;
            }else{
                slow = nullptr;
            }
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    // 删除链表倒数第k个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* init = new ListNode(-1);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = init;
        init->next = head;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        return init->next;
    }

    // 求两个链表第一个公共节点
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1!=p2){
            if(p1)
                p1 = p1->next;
            else
                p1 = pHead2;
            if(p2)
                p2 = p2->next;
            else
                p2 = pHead1;
        }
        return p1;
    }

    // 链表相加
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        //任意一个链表为空，返回另一个
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        //反转两个链表
        head1 = ReverseList(head1);
        head2 = ReverseList(head2);
        //添加表头
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        //进位符号
        int carry = 0;
        //只要某个链表还有或者进位还有
        while(head1 != NULL || head2 != NULL || carry != 0){
            //链表不为空则取其值
            int val1 = head1 == NULL ? 0 : head1->val;
            int val2 = head2 == NULL ? 0 : head2->val;
            //相加
            int temp = val1 + val2 + carry;
            //获取进位
            carry = temp / 10;  // 十位数字
            temp %= 10;  // 个位数字
            //添加元素
            head->next = new ListNode(temp);
            head = head->next;
            //移动下一个
            if(head1 != NULL)
                head1 = head1->next;
            if(head2 != NULL)
                head2 = head2->next;
        }
        //结果反转回来
        return ReverseList(res->next);
    }

    // 链表排序
    ListNode* sortInList(ListNode* head) {
        if(head==nullptr or head->next==nullptr){
            return head;
        }
        ListNode* left = head;
        ListNode* mid = head->next;
        ListNode* right = head->next->next;
        while(right and right->next){
            right = right->next->next;
            left = left->next;
            mid = mid->next;
        }
        left->next = nullptr;
        return Merge(sortInList(head), sortInList(mid));
    }

    // 判断一个链表是否为回文结构
    bool isPail(ListNode* head) {
        ListNode* p = head;
        int k = 0;
        while(p){
            k++;
            p = p->next;
        }
        k = k/2;
        p = head;
        while(k--){
            p = p->next;
        }
        p = ReverseList(p);
        ListNode* q = head;
        while(p){
            if(q->val==p->val){
                q = q->next;
                p = p->next;
            }else{
                return false;
            }
        }
        return true;
    }

    // 链表的奇偶重排
    ListNode* oddEvenList(ListNode* head) {
        // odd奇数，even偶数
        if(head==nullptr or head->next==nullptr){
            return head;
        }
        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* evenStart = even;
        while(even and even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }

    // 删除链表中重复元素，链表元素从小到大有序，使链表中所有元素只出现一次
    ListNode* deleteDuplicates1(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* cur = head;
        while(cur and cur->next){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }

    // 删除链表中重复元素，链表元素从小到大有序，只保留原链表中只出现一次的元素
    ListNode* deleteDuplicates2(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* res = new ListNode(-1);
        res->next = head;
        ListNode* cur = res;
        while(cur->next and cur->next->next){
            if(cur->next->val == cur->next->next->val){
                int n = cur->next->val;
                while(cur->next and cur->next->val == n){
                    cur->next = cur->next->next;
                }
            }else{
                cur = cur->next;
            }
        }
        return res->next;
    }
};