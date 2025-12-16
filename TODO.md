<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- TODO.md                                            :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2025/12/16 13:30:15 by rpinheir          #+#    #+#            -->
<!-- Updated: 2025/12/16 15:27:56 by rpinheir         ###   ########.ch      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

# Push_swap - TODO

## 🔴 BUGS À FIX EN PREMIER (avant append_node)

### BUG 1: process_arg() missing exit
- **Problème:** J'affiche "Error" mais la fonction continue
- [X] **Fix:** Ajouter `exit(1);` après `free_stack(a);`

### BUG 2: ft_listcount() off-by-one
- **Fichier:** ft_list_operations.c:34
- **Problème:** Loop condition `node != first_node->prev` rate le dernier node
- [X] **Fix:** Changer en `node->next != first_node` ou compter avant le check

### ✅ BUG 3: free_stack() infinite loop - FIXED
- [x] **Fichier:** ft_list_operations.c:54
- [x] **Fix:** Casse le cercle avec `(*stack)->prev->next = NULL` avant de free

### ✅ BUG 4: pos_change() infinite loop - FIXED
- [x] **Fichier:** push.c:60
- [x] **Fix:** Ajouté `node = node->next` + check `if (!stack || !*stack)`

### BUG 5: rotate() wrong pointer
- **Fichier:** rotate.c:38
-**Problème:** `*stack = first_node->prev` est faux (rotate = first devient last)
- [X] **Fix:** `*stack = first_node->next` (le 2ème node devient le premier)

### BUG 6: three_sort() compare pointer to value
- **Fichier:** three_sort.c:29
-**Problème:** `first_node->prev > first_node->value` compare pointeur et int
- [X] **Fix:** `first_node->prev->value > first_node->value`

### BUG 7: push() crashes si dest NULL
-**Fichier:** push.c:31
-**Problème:** Pas de NULL check avant de déréférencer dest
- [X] **Fix:** Ajouter check au début: `if (!dest || !*dest || !source || !*source) return;`

---

## 🟡 APRÈS LES BUGS: Implémenter append_node()

### Fonction append_node() - BLOQUANT
- [X] **Fichier:** Créer nouveau fichier ou ajouter dans ft_list_operations.c
- [X] **Prototype:** `void append_node(t_stack **stack, int value);`
- [ ] **Logique:**
  - [X] Créer nouveau node avec malloc
  - [X] Si stack vide: `node->prev = node; node->next = node;`
  - [X] Si stack non-vide: insérer à la fin et maintenir circular
- [X] **Décommenter:** push_swap.c:82 après implémentation

---

## 📋 TODO - Après append_node

### Makefile
- [X] Retirer `add_stack_node.c` de la ligne 8 (fichier existe pas)

### Sorting Algorithms
- [X] Debug three_sort()

---

## 🚀 TURK ALGORITHM - PLAN DÉTAILLÉ

### Structure de Fichiers
```
src/
├── turk_utils.c      → Phase 1 (utilitaires)
├── turk_a_to_b.c     → Phase 2 (push A vers B)
├── turk_b_to_a.c     → Phase 3 + 4 (push B vers A + final)
├── sort.c            → Phase 5 (main sort)
```

### PHASE 1: Fonctions Utilitaires
- [X] current_index(t_stack *stack) - assigne position à chaque node
- [X] set_median(t_stack *stack) - set above_median bool
- [X] find_min(t_stack *stack) - retourne node min
- [X] find_max(t_stack *stack) - retourne node max
- [X] is_sorted(t_stack *stack) - check si trié

### PHASE 2: Push A → B
- [X] get_target_b(t_stack *node, t_stack **stack) - trouve où placer node_a dans B

- [ ] calc_push_price(node, target) - calcule coût avec rr/rrr

- [ ] init_nodes_a(a, b) - setup target_node + push_price pour chaque node de A

- [ ] set_cheapest(stack) - marque le node le moins cher

- [ ] rotate_both(a, b, cheapest) - aligne cheapest et target avec rr/rrr

- [ ] push_a_to_b(a, b) - push le cheapest de A vers B


### PHASE 3: Push B → A
- [ ] get_target_a(node_b, a) - trouve où placer node_b dans A
- [ ] init_nodes_b(a, b) - setup target_node pour chaque node de B
- [ ] push_b_to_a(a, b) - push de B vers A

### PHASE 4: Finalisation
- [ ] final_rotate(a) - rotate jusqu'à min en haut

### PHASE 5: Main
- [ ] sort_stack(a, b) - logique principale qui appelle tout

### Rappels
- get_target_b: cherche le plus grand de B qui est < node_a
- get_target_a: cherche le plus petit de A qui est > node_b
- Optimisation rr/rrr: si both above_median ou both below → utilise rr/rrr
- Push vers B jusqu'à size_a == 3, puis three_sort, puis push tout vers A

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
