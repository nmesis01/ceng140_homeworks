#include "socialmedia.h"
#include <stdlib.h>
Database db;
Cache userCache;
Cache postCache;
int USER_CACHE(int userid)
{
  if (userCache.size)
  {
    Node *head;
    head = userCache.head;
    while (head)
    {
      if (((User *)head->data)->userId == userid)
      {
        return 1;
      }
      head = head->next;
    }
    return 0;
  }
  else
  {
    return 0;
  }
}
int POST_CACHE(int postid)
{
  if (postCache.size)
  {
    Node *head;
    head = postCache.head;
    while (head)
    {
      if (((Post *)head->data)->postId == postid)
      {
        return 1;
      }
      head = head -> next;
    }
    return 0;
  }
  else
  {
    return 0;
  }
}
void printUser(User *user) {  
  printf("User: %d, Username: %s, Followers: %d, Following: %d, Liked: %d\n",
         user->userId, user->username, user->numOfFollowers,
         user->numOfFollowing, user->liked);
}
void printPost(Post *post) {
  printf("Post: %d, Author: %s, Likes: %d\n", post->postId,
         post->author->username, post->likes);
}
void printUserCache(void) {
  /* TODO: Start from head and printUser */
  if (userCache.size)
  {
    Node *head;
    head = userCache.head;
    if (head)
    {
      printf("UserCache:\n");
      while (head)
      {
        printUser(head->data);
        head = head -> next;
      }   
    }
  }
}
void printPostCache(void) {
  /* TODO: Start from tail and printPost */
  if (postCache.size)
  {
    Node *tail;
    tail = postCache.tail;
    printf("PostCache:\n");
    while (tail)
    {
      printPost(tail->data);
      tail = tail -> prev;
    }
  }
}
Node *createNode(void *data)
{
   /* TODO */
   Node *p = (Node *)malloc(sizeof(Node));
   p -> data = data;
   p -> prev = NULL;
   p -> next = NULL;
   return p;
}
void appendToCache(Cache *cache, void *data) 
{
   /* TODO */ 
   if (cache -> size == 0)
   {
    Node *new;
    new = createNode(data);
    cache -> tail = new;
    cache -> head = new;
    cache -> size += 1;
   }
   else if(cache -> size == cache -> capacity)
   {
    removeLast(cache);
    appendToCache(cache , data);
   }
   else
   {
    Node *new;
    new = createNode(data);
    new -> next = cache -> head;
    cache -> head -> prev = new;
    cache -> head = new;
    cache -> size += 1;
   }
}
void moveToFront(Cache *cache, Node *node)
{
   /* TODO */
   int controller = 0;
   if (cache -> size)
   {
      Node *head = cache -> head;
      while (head)
      {
        if (head == node)
        {
          controller = 1;
          break;
        }
        head = head -> next;
      }
   } 
   if (controller && cache -> head != node )
   {
      node -> prev -> next = node -> next;
      if (cache -> tail == node)
      {
        cache -> tail = node -> prev;
      }
      else
      {
        node -> next -> prev = node -> prev;
      }
      node ->prev = NULL;
      node -> next = cache -> head;
      cache -> head -> prev = node;
      cache -> head = node;
   }
}
void removeLast(Cache *cache)
{
   /* TODO */
   if (cache -> size != 0 && cache -> tail)
   {
      Node *p = cache -> tail ->prev;
      free(cache -> tail);
      cache -> tail = p;
      if (cache -> size == 1)
      {
        cache -> head = NULL;
        cache -> tail = NULL;
      }
      else
      {
        cache -> tail -> next = NULL;
      }
      cache -> size -= 1;
   }
}
User *fetchUser(int userId) 
{ 
  /* TODO */
  if (userCache.size != 0 && USER_CACHE(userId))
  {
      Node *head;
      head = userCache.head;
      while (head)
      {
        if (((User *)(head->data)) -> userId == userId)
        {
          moveToFront(&userCache,head);
          return (User *)(head->data);
        }
        head = head->next;
      }
  }
  else
  {    
    appendToCache(&userCache,&db.users[userId]);
    return &db.users[userId];
  }
}
Post *fetchPost(int postId)
{
   /* TODO */
  if (postCache.size != 0 && POST_CACHE(postId))
  {
      Node *head;
      head = postCache.head;
      while (head)
      {
        if (((Post *)(head->data))-> postId == postId)
        {
          moveToFront(&postCache,head);
          return (Post *)(head->data);
        }
        head = head -> next;
      }
  }
  else
  {
    appendToCache(&postCache,&db.posts[postId]);
    return &db.posts[postId];
  }
}
void followUser(int followerId, int followedId)
{
  /* TODO Fetch followerId, followedId, then update followers of followedId */
  User *follower;
  User *followed;
  follower = fetchUser(followerId);
  followed = fetchUser(followedId);
  if (followed -> numOfFollowers == 0)
  {
    Node *p = createNode(follower);
    followed -> followers_head = p;
    followed -> followers_tail = p;
    followed -> numOfFollowers += 1;
  }
  else
  {
    Node *p = createNode(follower);
    p -> prev = followed -> followers_tail;
    followed -> followers_tail -> next = p;
    followed -> followers_tail = p;
    followed ->numOfFollowers += 1;
  }
  follower -> numOfFollowing += 1;
}
void likePost(int userId, int postId)
{ 
  /* TODO Fetch userId and postId */ 
  User *liker;
  Post *post;
  liker = fetchUser(userId);
  post = fetchPost(postId);
  post -> likes += 1;
  liker -> liked += 1;
}
void printFollowersInReverse(void) {
  /* For each user in the UserCache... */
  printf("Followers of all users in UserCache in reverse:\n");
  if (userCache.size)
  {
      Node *iter;
      iter = userCache.tail;
      while (iter)
      {
        Node *f;
        printf("Followers of user with id %d in reverse:\n",((User*)iter->data)->userId);
        f = ((User*)iter->data)->followers_tail;
        while (f)
        {
          printf("[%d] ",((User*)f->data)->userId);
          f = f->prev;
        }
        printf("\n");
        iter = iter -> prev;
      }
  }
}
void freeLinkedList(Node *head)
{
  /* TODO Free linked list nodes but not data or data's contents! */
  Node *n;
  Node *p;
  p = head;
  while (p)
  {
    n = p -> next;
    free(p);
    p = n;
  }
}
