SELECT b.REST_ID, b.REST_NAME, b.FOOD_TYPE, b.FAVORITES, b.ADDRESS, ROUND(AVG(a.REVIEW_SCORE),2) AS SCORE 
FROM REST_REVIEW a
JOIN REST_INFO b 
ON a.REST_ID = b.REST_ID
WHERE b.ADDRESS LIKE '서울%'
GROUP BY REST_ID
ORDER BY 6 DESC, 4 DESC;