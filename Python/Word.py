#GovRptWordCloudv2.py 
import wordcloud
import jieba
excludes = { }
f = open("共产党宣言.txt","r",encoding="utf-8")
t = f.read()
f.close()
ls = jieba.lcut(t)
txt = " ".join(ls)
w = wordcloud.WordCloud(width=1000,height=700,background_color="white",font_path="msyh.ttc")
w.generate(txt)
w.to_file("grwordcloudm.png")
