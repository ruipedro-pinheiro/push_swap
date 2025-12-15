# Push_swap - TODO

## 🔴 BUGS À FIX EN PREMIER (avant append_node)

### BUG 1: process_arg() missing exit
- [ ] **Fichier:** push_swap.c:80
- [ ] **Problème:** J'affiche "Error" mais la fonction continue
- [ ] **Fix:** Ajouter `exit(1);` après `free_stack(a);`

### BUG 2: ft_listcount() off-by-one
- [ ] **Fichier:** ft_list_operations.c:34
- [ ] **Problème:** Loop condition `node != first_node->prev` rate le dernier node
- [ ] **Fix:** Changer en `node->next != first_node` ou compter avant le check

### ✅ BUG 3: free_stack() infinite loop - FIXED
- [x] **Fichier:** ft_list_operations.c:54
- [x] **Fix:** Casse le cercle avec `(*stack)->prev->next = NULL` avant de free

### ✅ BUG 4: pos_change() infinite loop - FIXED
- [x] **Fichier:** push.c:60
- [x] **Fix:** Ajouté `node = node->next` + check `if (!stack || !*stack)`

### BUG 5: rotate() wrong pointer
- [ ] **Fichier:** rotate.c:38
- [ ] **Problème:** `*stack = first_node->prev` est faux (rotate = first devient last)
- [ ] **Fix:** `*stack = first_node->next` (le 2ème node devient le premier)

### BUG 6: three_sort() compare pointer to value
- [ ] **Fichier:** three_sort.c:29
- [ ] **Problème:** `first_node->prev > first_node->value` compare pointeur et int
- [ ] **Fix:** `first_node->prev->value > first_node->value`

### BUG 7: push() crashes si dest NULL
- [ ] **Fichier:** push.c:31
- [ ] **Problème:** Pas de NULL check avant de déréférencer dest
- [ ] **Fix:** Ajouter check au début: `if (!dest || !*dest || !source || !*source) return;`

---

## 🟡 APRÈS LES BUGS: Implémenter append_node()

### Fonction append_node() - BLOQUANT
- [ ] **Fichier:** Créer nouveau fichier ou ajouter dans ft_list_operations.c
- [ ] **Prototype:** `void append_node(t_stack **stack, int value);`
- [ ] **Logique:**
  - [ ] Créer nouveau node avec malloc
  - [ ] Si stack vide: `node->prev = node; node->next = node;`
  - [ ] Si stack non-vide: insérer à la fin et maintenir circular
- [ ] **Décommenter:** push_swap.c:82 après implémentation

---

## 📋 TODO - Après append_node

### Makefile
- [ ] Retirer `add_stack_node.c` de la ligne 8 (fichier existe pas)

### Sorting Algorithms
- [ ] Finir three_sort() (après fix du bug)
- [ ] Implémenter Turk Algorithm:
  - [ ] init_nodes_a()
  - [ ] init_nodes_b()
  - [ ] current_index()
  - [ ] set_cheapest()
  - [ ] Main sorting loop

### Testing
- [ ] Test edge cases (empty, single, duplicates)
- [ ] Benchmark (100 nums < 700 ops, 500 nums < 5500 ops)
- [ ] Test avec checker
- [ ] Valgrind memory leaks

---

## ✅ DONE

- [x] Swap operations (sa, sb, ss)
- [x] Push operations (pa, pb)
- [x] Rotate operations (ra, rb, rr)
- [x] Reverse rotate operations (rra, rrb, rrr)
- [x] Duplicate checking
- [x] Input validation
- [x] Argument parsing
- [x] **BUG FIX:** pos_change() - infinite loop (2025-12-14)
- [x] **BUG FIX:** free_stack() - infinite loop (2025-12-14)
- [x] **BUG FIX:** is_duplicate() - circular list check
