#include "list.h"
#include <gtest.h>
TEST(Forward_List, can_create_empty_list)
{
  ASSERT_NO_THROW(Forward_List<int> list);
}
TEST(Forward_List, can_create_not_empty_list)
{
  ASSERT_NO_THROW(Forward_List<int> list(5,1));
}
TEST(Forward_List, can_not_create_list_with_negative_size)
{
  EXPECT_ANY_THROW(Forward_List<int> list(-5,1));
}
TEST(Forward_List, pushback_elem_into_empty_list)
{
    Forward_List<int> list;
    ASSERT_NO_THROW(list.push_Back(3));
}
TEST(Forward_List, calculate_size_of_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    ASSERT_EQ(list.size(), 1);
}
TEST(Forward_List, pushback_element_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    ASSERT_EQ(list.pop_front(), 3);
}
TEST(Forward_List, can_create_copy_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    ASSERT_NO_THROW(Forward_List<int> list2(list));
}
TEST(Forward_List, copy_list_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    Forward_List<int> list2(list);
    EXPECT_EQ(list2.pop_front(),list.pop_front());
}
TEST(Forward_List, copy_list_has_own_memory)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    Forward_List<int> list2(list);
    list2.delete_Front();
    EXPECT_NE(list2.pop_front(),list.pop_front());
}
TEST(Forward_List, can_not_delete_from_empty_list)
{
    Forward_List<int> list;
    EXPECT_ANY_THROW(list.delete_Front());
}
TEST(Forward_List, can_delete_from_not_empty_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    EXPECT_NO_THROW(list.delete_Front());
}
TEST(Forward_List, delete_can_change_size_of_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    int s = list.size();
    list.delete_Front();
    EXPECT_NE(s, list.size());
}
TEST(Forward_List, delete_change_size_of_list_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    int s = list.size();
    list.delete_Front();
    EXPECT_EQ(s-1, list.size());
}
TEST(Forward_List, can_assign_list_to_itself)
{
    Forward_List<int> list;
    list.push_Back(3);
    ASSERT_NO_THROW(list = list);
}
TEST(Forward_List, can_assign_list_to_another_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    Forward_List<int> list2;
    ASSERT_NO_THROW(list2 = list);
}
TEST(Forward_List, assign_list_to_another_list_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    Forward_List<int> list2;
    list2 = list;
    EXPECT_EQ(list.pop_front(), list2.pop_front());
}
TEST(Forward_List, assign_list_has_own_memory)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    Forward_List<int> list2;
    list2 = list;
    list2.delete_Front();
    EXPECT_NE(list.pop_front(), list2.pop_front());
}
TEST(Forward_List, can_clear_list)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    ASSERT_NO_THROW(list.clear());
}
TEST(Forward_List, clear_list_is_empty)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.clear();
    EXPECT_EQ(true, list.empty());
}
TEST(Forward_List, can_not_shift_negative_count)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    EXPECT_ANY_THROW(list.shift_k_elem(-2));
}
TEST(Forward_List, can_shift_list_with_single_elem)
{
    Forward_List<int> list;
    list.push_Back(3);
    ASSERT_NO_THROW(list.shift_k_elem(6));
}
TEST(Forward_List, can_shift_list_correct)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    list.shift_k_elem(1);
    EXPECT_EQ(3, list.pop_front());
}
TEST(Forward_List, can_shift_list_with_large_k_fast)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    list.shift_k_elem(3000001);
    EXPECT_EQ(3, list.pop_front());
}
TEST(Forward_List, can_shift_list_with_divisible_size)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    list.shift_k_elem(300);
    EXPECT_EQ(1, list.pop_front());
}
TEST(Forward_List, can_shift_BIG_list_fast)
{
    Forward_List<int> list(1000, 1);
    list.shift_k_elem(500);
    EXPECT_EQ(501, list.pop_front());
}
TEST(Forward_List, can_find_existing_element)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    EXPECT_NE(nullptr, list.find(1));
}
TEST(Forward_List, find_existing_element_is_correct)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    Node<int> * e = list.find(1);
    EXPECT_EQ(1, e->element);
}
TEST(Forward_List, can_not_find_not_existing_element)
{
    Forward_List<int> list;
    list.push_Back(1);
    list.push_Back(2);
    list.push_Back(3);
    EXPECT_EQ(nullptr, list.find(5));
}
TEST(Forward_List, insert_element_after_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.push_Back(5);
    Node<int> * e = list.find(4);
    list.insert_after(e, 1);
    Node<int> * e1 = list.find(1);
    EXPECT_EQ(1, e1->element);
}
TEST(Forward_List, insert_element_after_change_size_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.push_Back(5);
    int a = list.size();
    Node<int> * e = list.find(4);
    list.insert_after(e, 1);
    int b = list.size();
    EXPECT_EQ(a+1,b);
}
TEST(Forward_List, delete_element_after_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.push_Back(5);
    Node<int> * e = list.find(4);
    list.delete_after(e);
    EXPECT_EQ(nullptr, list.find(5));
}
TEST(Forward_List, can_not_delete_after_last_element)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.push_Back(5);
    Node<int> * e = list.find(5);
    ASSERT_ANY_THROW(list.delete_after(e));
}
TEST(Forward_List, push_Front_is_correct)
{
    Forward_List<int> list;
    list.push_Back(3);
    list.push_Back(4);
    list.push_Front(2);
    EXPECT_EQ(2, list.pop_front());
}
