#include <iostream>
#include <string>
#include "algorithms.h"

void print_dsa_menu() {
    std::cout << "=== DSA Courses ===\n";
    std::cout << "1. DSA1 (10 homeworks)\n";
    std::cout << "2. DSA2 (15 homeworks)\n";
    std::cout << "3. DSA3 (10 homeworks)\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose course (0-3): ";
}

void print_hw_menu(int dsa_level) {
    std::cout << "=== DSA" << dsa_level << " - Homeworks ===\n";

    int max_hw = 0;
    switch (dsa_level) {
        case 1:
            max_hw = 10;
            break;
        case 2:
            max_hw = 15;
            break;
        case 3:
            max_hw = 10;
            break;
    }

    for (int i = 1; i <= max_hw; i++) {
        std::cout << i << ". HW" << i << "\n";
    }

    std::cout << "0. Back to courses\n";
    std::cout << "Choose homework (0-" << max_hw << "): ";
}

void print_dsa2_hw1_algorithms() {
    std::cout << "=== DSA2 HW1 ===\n";
    std::cout << "1. Depth-first search\n";
    std::cout << "2. Connected components\n";
    std::cout << "3. Cheating (Bipartite check)\n";
    std::cout << "4. Cycle detection\n";
    std::cout << "5. Which vertices can reach the first vertex\n";
    std::cout << "6. Subtree sizes\n";
    std::cout << "7. Transport system optimization\n";
    std::cout << "8. Room area\n";
    std::cout << "9. Byte Radio\n";
    std::cout << "10. Landing troops\n";
    std::cout << "0. Back to homeworks\n";
    std::cout << "Choose an algorithm (0-10): ";
}

void print_dsa2_hw2_algorithms() {
    std::cout << "=== DSA2 HW2 ===\n";
    std::cout << "1. Topological sort\n";
    std::cout << "2. Find bridges\n";
    std::cout << "3. Articulation points\n";
    std::cout << "4. Graph condensation\n";
    std::cout << "5. One-way traffic\n";
    std::cout << "6. Parts production\n";
    std::cout << "7. Apple tree\n";
    std::cout << "8. Study groups\n";
    std::cout << "9. City republic\n";
    std::cout << "10. Prime minister\n";
    std::cout << "0. Back to homeworks\n";
    std::cout << "Choose an algorithm (0-10): ";
}

void print_dsa2_hw3_algorithms() {
    std::cout << "=== DSA2 HW3 ===\n";
    std::cout << "1. Shortest path length\n";
    std::cout << "2. Path in a graph\n";
    std::cout << "3. Spelunker's path\n";
    std::cout << "4. Fleas\n";
    std::cout << "5. Redundant edges\n";
    std::cout << "6. Metro\n";
    std::cout << "7. Toy maze\n";
    std::cout << "8. Max and pourings\n";
    std::cout << "9. Tsar Leonid on a tractor\n";
    std::cout << "10. Robots\n";
    std::cout << "0. Back to homeworks\n";
    std::cout << "Choose an algorithm (0-10): ";
}

// ====== DSA2 HW4 menu ======
void print_dsa2_hw4_algorithms() {
    std::cout << "=== DSA2 HW4 ===\n";
    std::cout << "1. Dijkstra\n";
    std::cout << "2. Dijkstra with path reconstruction\n";
    std::cout << "3. Fast Dijkstra\n";
    std::cout << "4. Shortest path\n";
    std::cout << "5. Alchemy Olympiad\n";
    std::cout << "6. Buses in Vasyuki\n";
    std::cout << "7. Riding City\n";
    std::cout << "8. Transportation\n";
    std::cout << "9. By Sled\n";
    std::cout << "10. File manager\n";
    std::cout << "0. Back to homeworks\n";
    std::cout << "Choose an algorithm (0-10): ";
}
// ================================

// ====== DSA2 HW5 menu ======
void print_dsa2_hw5_algorithms() {
    std::cout << "=== DSA2 HW5 ===\n";
    std::cout << "A. Transitive Closure\n";
    std::cout << "B. Is there a cycle?\n";
    std::cout << "C. Floyd\n";
    std::cout << "D. Dangerous Route\n";
    std::cout << "E. The Longest Path\n";
    std::cout << "F. Pink Floyd\n";
    std::cout << "G. Ford-Bellman\n";
    std::cout << "H. Timed Flights\n";
    std::cout << "I. Negative Weight Cycle\n";
    std::cout << "J. Labyrinth of Knowledge\n";
    std::cout << "0. Back to homeworks\n";
    std::cout << "Choose an algorithm (0-10): ";
}
// =================================

void print_not_implemented_message(int dsa_level, int hw_number) {
    std::cout << "\n=== DSA" << dsa_level << " HW" << hw_number << " ===\n";
    std::cout << "This homework is not implemented yet.\n";
    std::cout << "Check GitHub for updates: https://github.com/VladislavCherniavskii/DSA\n";
}

int transportation() {
    int dsa_choice = -1;
    int hw_choice = -1;
    int algo_choice = -1;

    while (dsa_choice != 0) {
        print_dsa_menu();
        std::cin >> dsa_choice;

        if (dsa_choice == 0) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (dsa_choice < 1 || dsa_choice > 3) {
            std::cout << "Invalid course choice! Please try again.\n";
            continue;
        }

        hw_choice = -1;
        while (hw_choice != 0) {
            print_hw_menu(dsa_choice);
            std::cin >> hw_choice;

            if (hw_choice == 0) {
                break;
            }

            int max_hw = (dsa_choice == 1) ? 10 : (dsa_choice == 2) ? 15 : 10;
            if (hw_choice < 1 || hw_choice > max_hw) {
                std::cout << "Invalid homework choice! Please try again.\n";
                continue;
            }

            if (dsa_choice == 2 && hw_choice == 1) {
                algo_choice = -1;
                while (algo_choice != 0) {
                    print_dsa2_hw1_algorithms();
                    std::cin >> algo_choice;

                    switch (algo_choice) {
                        case 1:
                            std::cout << "\n=== Depth-first Search ===\n";
                            depth_first_search();
                            break;
                        case 2:
                            std::cout << "\n=== Connected Components ===\n";
                            connected_components();
                            break;
                        case 3:
                            std::cout << "\n=== Cheating (Bipartite Check) ===\n";
                            cheating();
                            break;
                        case 4:
                            std::cout << "\n=== Cycle Detection ===\n";
                            cycle_detection();
                            break;
                        case 5:
                            std::cout << "\n=== Reachable Vertices ===\n";
                            reachable_vertices();
                            break;
                        case 6:
                            std::cout << "\n=== Subtree Sizes ===\n";
                            subtree_sizes();
                            break;
                        case 7:
                            std::cout << "\n=== Transport System Optimization ===\n";
                            transport_optimization();
                            break;
                        case 8:
                            std::cout << "\n=== Room Area ===\n";
                            room_area();
                            break;
                        case 9:
                            std::cout << "\n=== Byte Radio ===\n";
                            byte_radio();
                            break;
                        case 10:
                            std::cout << "\n=== Landing Troops ===\n";
                            landing_troops();
                            break;
                        case 0:
                            std::cout << "Returning to homeworks...\n";
                            break;
                        default:
                            std::cout << "Invalid algorithm choice! Please try again.\n";
                            break;
                    }

                    if (algo_choice != 0) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
            } else if (dsa_choice == 2 && hw_choice == 2) {
                algo_choice = -1;
                while (algo_choice != 0) {
                    print_dsa2_hw2_algorithms();
                    std::cin >> algo_choice;

                    switch (algo_choice) {
                        case 1:
                            std::cout << "\n=== Topological Sort ===\n";
                            topological_sort();
                            break;
                        case 2:
                            std::cout << "\n=== Find Bridges ===\n";
                            find_bridges();
                            break;
                        case 3:
                            std::cout << "\n=== Articulation Points ===\n";
                            articulation_points();
                            break;
                        case 4:
                            std::cout << "\n=== Graph Condensation ===\n";
                            graph_condensation();
                            break;
                        case 5:
                            std::cout << "\n=== One-Way Traffic ===\n";
                            one_way_traffic();
                            break;
                        case 6:
                            std::cout << "\n=== Parts Production ===\n";
                            parts_production();
                            break;
                        case 7:
                            std::cout << "\n=== Apple Tree ===\n";
                            apple_tree();
                            break;
                        case 8:
                            std::cout << "\n=== Study Groups ===\n";
                            study_groups();
                            break;
                        case 9:
                            std::cout << "\n=== City Republic ===\n";
                            city_republic();
                            break;
                        case 10:
                            std::cout << "\n=== Prime Minister ===\n";
                            prime_minister();
                            break;
                        case 0:
                            std::cout << "Returning to homeworks...\n";
                            break;
                        default:
                            std::cout << "Invalid algorithm choice! Please try again.\n";
                            break;
                    }

                    if (algo_choice != 0) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
            } else if (dsa_choice == 2 && hw_choice == 3) {
                algo_choice = -1;
                while (algo_choice != 0) {
                    print_dsa2_hw3_algorithms();
                    std::cin >> algo_choice;

                    switch (algo_choice) {
                        case 1:
                            std::cout << "\n=== Shortest Path Length ===\n";
                            shortest_path_length();
                            break;
                        case 2:
                            std::cout << "\n=== Path in a Graph ===\n";
                            path_in_graph();
                            break;
                        case 3:
                            std::cout << "\n=== Spelunker's Path ===\n";
                            spelunker_path();
                            break;
                        case 4:
                            std::cout << "\n=== Fleas ===\n";
                            fleas();
                            break;
                        case 5:
                            std::cout << "\n=== Redundant Edges ===\n";
                            redundant_edges();
                            break;
                        case 6:
                            std::cout << "\n=== Metro ===\n";
                            metro();
                            break;
                        case 7:
                            std::cout << "\n=== Toy Maze ===\n";
                            toy_maze();
                            break;
                        case 8:
                            std::cout << "\n=== Max and Pourings ===\n";
                            max_pourings();
                            break;
                        case 9:
                            std::cout << "\n=== Tsar Leonid on a Tractor ===\n";
                            tsar_leonid_tractor();
                            break;
                        case 10:
                            std::cout << "\n=== Robots ===\n";
                            robots();
                            break;
                        case 0:
                            std::cout << "Returning to homeworks...\n";
                            break;
                        default:
                            std::cout << "Invalid algorithm choice! Please try again.\n";
                            break;
                    }

                    if (algo_choice != 0) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
            }
            // ====== DSA2 HW4 handling ======
            else if (dsa_choice == 2 && hw_choice == 4) {
                algo_choice = -1;
                while (algo_choice != 0) {
                    print_dsa2_hw4_algorithms();
                    std::cin >> algo_choice;

                    switch (algo_choice) {
                        case 1:
                            std::cout << "\n=== Dijkstra ===\n";
                            dijkstra();
                            break;
                        case 2:
                            std::cout << "\n=== Dijkstra with path reconstruction ===\n";
                            dijkstra_with_path_reconstruction();
                            break;
                        case 3:
                            std::cout << "\n=== Fast Dijkstra ===\n";
                            fast_dijkstra();
                            break;
                        case 4:
                            std::cout << "\n=== Shortest Path ===\n";
                            shortest_path();
                            break;
                        case 5:
                            std::cout << "\n=== Alchemy Olympiad ===\n";
                            alchemy_olympiad();
                            break;
                        case 6:
                            std::cout << "\n=== Buses in Vasyuki ===\n";
                            buses_in_vasyuki();
                            break;
                        case 7:
                            std::cout << "\n=== Riding City ===\n";
                            riding_city();
                            break;
                        case 8:
                            std::cout << "\n=== Transportation ===\n";
                            // вызов переименованной функции
                            conveyance();
                            break;
                        case 9:
                            std::cout << "\n=== By Sled ===\n";
                            by_sled();
                            break;
                        case 10:
                            std::cout << "\n=== File manager ===\n";
                            file_manager();
                            break;
                        case 0:
                            std::cout << "Returning to homeworks...\n";
                            break;
                        default:
                            std::cout << "Invalid algorithm choice! Please try again.\n";
                            break;
                    }

                    if (algo_choice != 0) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
            }
            // ====== DSA2 HW5 handling ======
            else if (dsa_choice == 2 && hw_choice == 5) {
                algo_choice = -1;
                while (algo_choice != 0) {
                    print_dsa2_hw5_algorithms();
                    std::cin >> algo_choice;

                    switch (algo_choice) {
                        case 1:
                            std::cout << "\n=== A. Transitive Closure ===\n";
                            transitive_closure();
                            break;
                        case 2:
                            std::cout << "\n=== B. Is there a cycle? ===\n";
                            is_there_a_cycle();
                            break;
                        case 3:
                            std::cout << "\n=== C. Floyd ===\n";
                            floyd();
                            break;
                        case 4:
                            std::cout << "\n=== D. Dangerous Route ===\n";
                            dangerous_route();
                            break;
                        case 5:
                            std::cout << "\n=== E. The Longest Path ===\n";
                            the_longest_path();
                            break;
                        case 6:
                            std::cout << "\n=== F. Pink Floyd ===\n";
                            pink_floyd();
                            break;
                        case 7:
                            std::cout << "\n=== G. Ford-Bellman ===\n";
                            FordBellman();
                            break;
                        case 8:
                            std::cout << "\n=== H. Timed Flights ===\n";
                            timed_flights();
                            break;
                        case 9:
                            std::cout << "\n=== I. Negative Weight Cycle ===\n";
                            negative_weight_cycle();
                            break;
                        case 10:
                            std::cout << "\n=== J. Labyrinth of Knowledge ===\n";
                            labyrinth_of_knowledge();
                            break;
                        case 0:
                            std::cout << "Returning to homeworks...\n";
                            break;
                        default:
                            std::cout << "Invalid algorithm choice! Please try again.\n";
                            break;
                    }

                    if (algo_choice != 0) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }
                }
            }
            // =======================================

            // =======================================

            else {
                print_not_implemented_message(dsa_choice, hw_choice);
            }

            if (hw_choice != 0) {
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }
        }
    }

    return 0;
}

int main() {
    return transportation();
}
