# Sort-Performance
作業: 排序效能對比.

發現:
1. int型態和long型態是一樣的.
2. 排序過程使用vector會比array慢.

當前問題:
1. 10萬筆以上資料在std::array中會出現Exception has occurred. Segmentation fault
2. 程式碼規劃沒有考慮到輸出檔案的問題, 輸出部分的程式碼重複性太高, 很雜亂.