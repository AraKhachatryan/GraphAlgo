//*************  GraphAlgo: Algorithms library for planar graphs  *************
//  @file  GraphAlgo.hpp
//  @brief namespace GraphAlgo
//  @brief heare are included all header files for namespace GraphAlgo
//  @brief this file is part of GraphAlgo: Algorithms library for planar graphs
//.............................................................................
// @brief planar graph with 16 vertices and 25 edges
//
//             2 . . . . . . . . . 5                   8 . . . . . . . . . 16
//           .   .                   .                   .               . .
//         .       .                   .                   .           .   .
//       .           .                   .                   .       .     .
//     .               .                   .                   .   .       .
//   1 . . . . . . . . . 4 . . . . . . . . . 7 . . . . . . . . . 10        .
//                     .   .                 .                 .           .
//                   .       .               .               .             .
//                 .           .             .             .               .
//               .               .           .           .                 .
//             3 . . . . . . . . . 6         .         9 . . . . . . . . . 15
//           .   .               .   .       .       .                   . 
//         .       .           .       .     .     .                   .   
//       .           .       .           .   .   .                   .     
//     .               .   .               . . .                   .       
//  13 . . . . . . . . . 12                 11 . . . . . . . . . 14        
//
//.............................................................................
//  @brief Printing same graph as adjacency-list:
//          1  -->  2,  4
//          2  -->  1,  4,  5
//          3  -->  4,  6, 12, 13
//          4  -->  1,  2,  3,  6,  7
//          5  -->  2,  7
//          6  -->  3,  4, 11, 12
//          7  -->  4,  5, 10, 11
//          8  --> 10, 16
//          9  --> 10, 11, 15
//         10  -->  7,  8,  9, 16
//         11  -->  6,  7,  9, 14
//         12  -->  3,  6, 13
//         13  -->  3, 12
//         14  --> 11, 15
//         15  -->  9, 14, 16
//         16  -->  8, 10, 15
//.............................................................................
//  @version: 1.0.1
//  @author: Ara Khachatryan
//*****************************************************************************

#pragma once

#include "graph.hpp"
#include "dfs.hpp"
#include "connectivity.hpp"
#include "biconnectivity.hpp"
#include "dijkstra.hpp"
