#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
template <typename T, typename C = std::less<>>
using ordered_set =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, C, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

// order_of_key(num), find_by_order(key)

//  ordered_set<int, less_equal<int>> st;
