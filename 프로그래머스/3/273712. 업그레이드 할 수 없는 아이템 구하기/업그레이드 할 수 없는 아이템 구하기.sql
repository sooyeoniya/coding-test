SELECT ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO
WHERE ITEM_ID NOT IN (SELECT DISTINCT PARENT_ITEM_ID 
                      FROM ITEM_TREE 
                      WHERE PARENT_ITEM_ID IS NOT NULL)
ORDER BY ITEM_ID DESC

# SELECT ITEM_ID, ITEM_NAME, RARITY
# FROM ITEM_INFO
# WHERE ITEM_ID NOT IN (SELECT PARENT_ITEM_ID 
#                       FROM ITEM_TREE 
#                       GROUP BY PARENT_ITEM_ID 
#                       HAVING PARENT_ITEM_ID IS NOT NULL)
# ORDER BY ITEM_ID DESC