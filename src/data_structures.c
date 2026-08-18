#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"
#include "utils.h"

/* --- Singly Linked List --- */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static void print_linked_list(Node* head) {
    printf(COLOR_CYAN "Linked List Structure:\n" COLOR_RESET);
    if (!head) {
        printf(COLOR_YELLOW "  [HEAD] -> NULL (Empty List)\n" COLOR_RESET);
        return;
    }
    printf("  [HEAD] -> ");
    Node* curr = head;
    while (curr) {
        printf(COLOR_GREEN "[%d|•]" COLOR_RESET " ──> ", curr->data);
        curr = curr->next;
    }
    printf(COLOR_RED "NULL\n" COLOR_RESET);
}

static void demo_linked_list(void) {
    Node* head = NULL;
    int opt = 0, val = 0;

    while (1) {
        clear_screen();
        print_header("LESSON 2.1: SINGLY LINKED LIST", "Interactive dynamic node allocation");
        print_linked_list(head);
        printf("\n" COLOR_GREEN "  [1] Append Node\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Prepend Node (at Head)\n" COLOR_RESET);
        printf(COLOR_GREEN "  [3] Delete Node by Value\n" COLOR_RESET);
        printf(COLOR_RED   "  [4] Return to Data Structures Menu\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Choose action (1-4): " COLOR_RESET);

        if (scanf("%d", &opt) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (opt == 4) break;

        if (opt == 1 || opt == 2) {
            printf(COLOR_WHITE "Enter integer value to insert: " COLOR_RESET);
            if (scanf("%d", &val) != 1) {
                while (getchar() != '\n');
                continue;
            }
            Node* newNode = create_node(val);
            if (opt == 2 || !head) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
        } else if (opt == 3) {
            printf(COLOR_WHITE "Enter value to delete: " COLOR_RESET);
            if (scanf("%d", &val) != 1) {
                while (getchar() != '\n');
                continue;
            }
            if (!head) continue;
            if (head->data == val) {
                Node* toDelete = head;
                head = head->next;
                free(toDelete);
            } else {
                Node* prev = head;
                while (prev->next && prev->next->data != val) {
                    prev = prev->next;
                }
                if (prev->next) {
                    Node* toDelete = prev->next;
                    prev->next = toDelete->next;
                    free(toDelete);
                }
            }
        }
    }

    // Free remaining list
    while (head) {
        Node* next = head->next;
        free(head);
        head = next;
    }
}

/* --- Stack (LIFO) --- */
#define STACK_CAP 5
static void demo_stack(void) {
    int stack[STACK_CAP];
    int top = -1;
    int opt = 0, val = 0;

    while (1) {
        clear_screen();
        print_header("LESSON 2.2: STACK (LIFO: Last In, First Out)", "Push, Pop, and Peek visualizer");

        printf(COLOR_CYAN "Visual Stack Buffer:\n" COLOR_RESET);
        for (int i = STACK_CAP - 1; i >= 0; i--) {
            if (i == top) {
                printf(COLOR_GREEN "  | %4d | <-- TOP (Index %d)\n" COLOR_RESET, stack[i], i);
            } else if (i < top) {
                printf("  | %4d |\n", stack[i]);
            } else {
                printf(COLOR_WHITE "  |      | [Empty Slot %d]\n" COLOR_RESET, i);
            }
        }
        printf("  +------+\n\n");

        printf(COLOR_GREEN "  [1] Push Element\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Pop Element\n" COLOR_RESET);
        printf(COLOR_RED   "  [3] Return to Data Structures Menu\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Choose action (1-3): " COLOR_RESET);

        if (scanf("%d", &opt) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (opt == 3) break;

        if (opt == 1) {
            if (top >= STACK_CAP - 1) {
                printf(COLOR_RED "\n[Stack Overflow] Cannot push to full stack!\n" COLOR_RESET);
                sleep_ms(1000);
            } else {
                printf(COLOR_WHITE "Enter integer to push: " COLOR_RESET);
                if (scanf("%d", &val) == 1) {
                    stack[++top] = val;
                }
            }
        } else if (opt == 2) {
            if (top < 0) {
                printf(COLOR_RED "\n[Stack Underflow] Stack is already empty!\n" COLOR_RESET);
                sleep_ms(1000);
            } else {
                printf(COLOR_YELLOW "\nPopped value: %d\n" COLOR_RESET, stack[top--]);
                sleep_ms(800);
            }
        }
    }
}

/* --- Binary Search Tree --- */
typedef struct BSTNode {
    int val;
    struct BSTNode *left, *right;
} BSTNode;

static BSTNode* bst_insert(BSTNode* root, int val) {
    if (!root) {
        BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
        n->val = val;
        n->left = n->right = NULL;
        return n;
    }
    if (val < root->val) root->left = bst_insert(root->left, val);
    else if (val > root->val) root->right = bst_insert(root->right, val);
    return root;
}

static void bst_inorder(BSTNode* root) {
    if (!root) return;
    bst_inorder(root->left);
    printf(COLOR_GREEN "%d " COLOR_RESET, root->val);
    bst_inorder(root->right);
}

static void bst_free(BSTNode* root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

static void demo_bst(void) {
    BSTNode* root = NULL;
    int initial_values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = bst_insert(root, initial_values[i]);
    }

    clear_screen();
    print_header("LESSON 2.3: BINARY SEARCH TREE (BST)", "Recursive Tree structure and in-order traversal");

    printf(COLOR_CYAN "Visual Representation of Tree:\n\n" COLOR_RESET);
    printf("            [50]          \n");
    printf("           /    \\        \n");
    printf("        [30]    [70]      \n");
    printf("        /  \\    /  \\     \n");
    printf("     [20] [40][60] [80]   \n\n");

    printf(COLOR_YELLOW "In-Order Traversal (Sorted Output: Left -> Root -> Right):\n  " COLOR_RESET);
    bst_inorder(root);
    printf("\n\n");

    printf(COLOR_WHITE "Time Complexity:\n" COLOR_RESET);
    printf("  • Search: Average O(log N), Worst O(N)\n");
    printf("  • Insertion: Average O(log N)\n");

    bst_free(root);
    pause_prompt();
}

void run_data_structures_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 2: DATA STRUCTURES IN C", "Building fundamental data representations from scratch");
        printf(COLOR_GREEN "  [1] Singly Linked List (Dynamic Node Allocation)\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Stack Buffer (Push/Pop/Overflow/Underflow)\n" COLOR_RESET);
        printf(COLOR_GREEN "  [3] Binary Search Tree (Recursive Traversal)\n" COLOR_RESET);
        printf(COLOR_RED   "  [4] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-4): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_linked_list(); break;
            case 2: demo_stack(); break;
            case 3: demo_bst(); break;
            case 4: return;
            default: break;
        }
    }
}
