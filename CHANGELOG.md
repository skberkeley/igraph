# igraph C library changelog

## [0.8.4]

### Added

### Changed

### Fixed

 - `igraph_i_cattribute_combine_vertices()`: fixed invalid cleanup code that eventually filled up the "finally" stack when combining vertices with attributes extensively.
 - `igraph_hrg_sample()`: fixed incorrect function prototype
 - `igraph_is_posinf()` and `igraph_is_neginf()`: fixed incorrect result on platforms where the sign of the result of `isinf()` is not indicative of the sign of the input.
 - Fixed building with vendored LAPACK and external BLAS
 - Fixed building with XCode 12.2 on macOS

### Other

 - Documentation improvements
 - General code cleanup to reduce the number of compiler warnings

## [0.8.3]

### Added

 - `igraph_vector_binsearch_slice()` performs binary search on a sorted slice of a vector.

### Changed

 - `igraph_eigenvector_centrality()` assumes the adjacency matrix of undirected graphs to have twice the number of self-loops for each vertex on the diagonal. This makes the results consistent between an undirected graph and its directed equivalent when each edge is replaced by a mutual edge pair.

### Fixed

 - `igraph_isomorphic()` now verifies that the input graphs have no multi-edges (PR #1464).
 - `igraph_difference()` was creating superfluous self loops (#597).
 - `igraph_count_multiple()` was giving incorrect results for self-loops in directed graph (PR #1399).
 - `igraph_betweenness_estimate()`: fixed incorrect results with finite cutoff (PR #1392).
 - `igraph_eigen_matrix_symmetric()`: fixed incorrect matrix multiplication (PR #1379).
 - Corrected several issues that could arise during an error condition (PRs #1405, #1406, #1438).
 - `igraph_realize_degree_sequence()` did not correctly detect some non-graphical inputs.
 - `igraph_is_graphical_degree_sequence()`: fixed incorrect results in undirected case (PR #1441).
 - `igraph_community_leiden()`: fixed incorrect result when self-loops are present (PR #1476).
 - `igraph_eigenvector_centrality()`: fixed incorrect value for isolated vertices in weighted graphs.
 - `igraph_eigenvector_centrality()`: corrected the handling of self-loops.
 - `igraph_layout_reingold_tilford()`: fixed an issue where branches of the tree would sometimes overlap. 

### Other

 - `igraph_degree_sequence_game()`: improved performance with `IGRAPH_DEGSEQ_SIMPLE_NO_MULTIPLE_UNIFORM` method.
 - Improved the robustness of the test suite.
 - Documentation improvements.
 - Improved error and warning messages.
 - Improved compatibility with recent versions of Microsoft Visual C.

## [0.8.2] - 2020-04-28

### Changed

 - Improved argument checking: `igraph_all_st_mincuts()` and `igraph_sir()`
 - Improved interruptibility: `igraph_sir()`

### Fixed

 - `igraph_community_leiden()`: fixed crash when interrupting
 - The tests are now more robust. Some incorrect test failures were fixed when
   running on i386 architecture, or when using different versions of external
   dependencies.

### Other

 - Improved error messages from `igraph_sir()`.
 - Improved compatibility with more recent versions of Microsoft Visual C.

## [0.8.1] - 2020-03-13

### Changed

 - Improved interruptability: `igraph_degree_sequence_game()`
 - Improved argument checking: `igraph_forest_fire_game()`
 - Updated the plfit library to version 0.8.1

### Fixed

 - `igraph_community_edge_betweenness()`: fix for graphs with no edges (PR #1312)
 - `igraph_bridges()` now handles multigraphs correctly (PR #1335)
 - `igraph_avg_nearest_neighbor_degree()`: fix for memory leak in weighted case (PR #1339)
 - `igraph_community_leiden()`: fix crash bug (PR #1357)

### Other

 - Included `ACKOWLEDGEMENTS.md`
 - Documentation improvements

## [0.8.0] - 2020-01-29

### Added

 * Trees

   - `igraph_to_prufer()` and `igraph_from_prufer()` convert labelled trees to/from Prüfer sequences
   - `igraph_tree_game()` samples uniformly from the set of labelled trees
   - `igraph_is_tree()` checks if a graph is a tree
   - `igraph_random_spanning_tree()` picks a spanning tree of a graph uniformly at random
   - `igraph_random_edge_walk()` returns the indices of edges traversed by a random walk; useful for multigraphs

 * Community detection

   - `igraph_community_fluid_communities()` detects communities based on interacting fluids
   - `igraph_community_leiden()` detects communities with the Leiden method

 * Cliques

   - `igraph_maximal_cliques_hist()` counts maximal cliques of each size
   - `igraph_maximal_cliques_callback()` calls a function for each maximal clique
   - `igraph_clique_size_hist()` counts cliques of each size
   - `igraph_cliques_callback()` calls a function for each clique
   - `igraph_weighted_cliques()` finds weighted cliques in graphs with integer vertex weights
   - `igraph_weighted_clique_number()` computes the weighted clique number
   - `igraph_largest_weighted_cliques()` finds the largest weighted cliques

 * Graph generators

   - `igraph_hsbm_game()` for a hierarchical stochastic block model
   - `igraph_hsbm_list_game()` for a more general hierarchical stochastic block model
   - `igraph_correlated_game()` generates pairs of correlated random graphs by perturbing existing adjacency matrix
   - `igraph_correlated_pair_game()` generates pairs of correlated random graphs
   - `igraph_tree_game()` samples uniformly from the set of labelled trees
   - `igraph_dot_product_game()` generates a random dot product graph
   - `igraph_realize_degree_sequence()` creates a single graph with a given degree sequence (Havel-Hakimi algorithm)

 * Graph embeddings

   - `igraph_adjacency_spectral_embedding()` and `igraph_laplacian_spectral_embedding()` provide graph embedddings
   - `igraph_dim_select()` provides dimensionality selection for singular values using profile likelihood

 * Isomorphism

   - `igraph_automorphism_group()` computes the generators of the automorphism group of a simple graph
   - `igraph_simplify_and_colorize()` encodes edge and self-loop multiplicities into edge and vertex colors; use in conjunction with VF2 to test isomorphism of non-simple graphs

 * Other

   - `igraph_bridges()` finds edges whose removal would disconnect a graph
   - `igraph_vertex_coloring_greedy()` computes a vertex coloring using a greedy algorithm
   - `igraph_rewire_directed_edges()` randomly rewires only the starting points or only the endpoints of directed edges
   - Various `igraph_local_scan_*` functions provide local counts and statistics of neighborhoods
   - `igraph_sample_sphere_surface()` samples points uniformly from the surface of a sphere
   - `igraph_sample_sphere_volume()` samples points uniformly from the volume of a sphere
   - `igraph_sample_dirichlet()` samples points from a Dirichlet distribution
   - `igraph_malloc()`, to be paired with the existing `igraph_free()`

### Changed

 - `igraph_degree_sequence_game()`: new method added for uniform sampling: `IGRAPH_DEGSEQ_SIMPLE_NO_MULTIPLE_UNIFORM`
 - `igraph_modularity_matrix()`: removed `membership` argument (PR #1194)
 - `igraph_avg_nearest_neighbor_degree()`: added `mode` and `neighbor_degree_mode` arguments (PR #1214).
 - `igraph_get_all_simple_paths()`: added `cutoff` argument (PR #1232).
 - `igraph_unfold_tree()`: no longer preserves edge ordering of original graph
 - `igraph_decompose()`: support strongly connected components
 - `igraph_isomorphic_bliss()`, `igraph_canonical_permutation()`, `igraph_automorphisms()`: added additional arguments to support vertex colored graphs (PR #873)
 - `igraph_extended_chordal_ring`: added argument to support direction (PR #1096), and fixed issue #1093.

### Other

 - The [Bliss isomorphism library](http://www.tcs.hut.fi/Software/bliss/) was updated to version 0.73. This version adds support for vertex colored and directed graphs.
 - igraph now uses the high-performance [Cliquer library](https://users.aalto.fi/~pat/cliquer.html) to find (non-maximal) cliques
 - Provide proper support for Windows, using `__declspec(dllexport)` and `__declspec(dllimport)` for `DLL`s and static usage by using `#define IGRAPH_STATIC 1`.
 - Provided integer versions of `dqueue` and `stack` data types.
