<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- TODO.md                                            :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2025/12/16 13:30:15 by rpinheir          #+#    #+#            -->
<!-- Updated: 2025/12/17 17:47:20 by rpinheir         ###   ########.ch      -->
<!--                                                                         -->
<!-- *********************************************************************** -->
--

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

- [X] calc_push_price(node, target) - calcule coût avec rr/rrr

- [X] init_nodes_a(a, b) - setup target_node + push_price pour chaque node de A

- [X] set_cheapest(stack) - marque le node le moins cher

- [? ] rotate_both(a, b, cheapest) - aligne cheapest et target avec rr/rrr


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
