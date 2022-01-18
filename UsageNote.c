//time:2022年1月16日21:37:52

---------------------------------------------安装Git--------------------------------------------------

1、在Windows上安装Git，安装完毕之后，初始化姓名邮箱
	git config --global user.name "Your Name"
	git config --global user.email "email@example.com"
2、注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置



---------------------------------------------创建版本库方法-------------------------------------------

1、创建一个空的GitHub
命令是
	mkdir flodername
	cd  flodername
	pwd  //显示你当前所在位置

2、初始化版本库
	使用命令 git init


	
3、添加（上传）一个文件，需要分三步
	1）先在本地创建一个文件（比如txt、md、c等）//最好不要使用记事本创建，可以更改为.c文件用notepad++写
	2）使用 git add  filename   //将本地的文件添加，可反复多次使用，添加多个文件；
	3）使用 git commit -m "添加提交说明"  //将添加的文件提交到GitHub，可以一次添加多个文件

特别提醒：以上所有命令操作都是在自己的GitHub里面操作。

---------------------------------------------查看修改--------------------------------------------------

1、修改文件后查看提交状态
	git status//查看是否有需要有添加和提交的文件
	git diff  //对比展示详细的修改区别
	git add    
	git commit //再次重新添加和提交已修改的文件，完成提交
	
注意：
	1）要明白这3个概念，工作区（working tree），暂存区（index /stage），本地仓库（repository）
		git跟不同的参数，比较不同的区间的版本。
		git diff：是查看working tree与index的差别的。
		git diff --cached：是查看index与repository的差别的。
		git diff HEAD：是查看working tree和repository的差别的。其中：HEAD代表的是最近的一次commit的信息。
	综上所述：git diff 后面跟文件名称是是查看工作区（working tree）与暂存区（index）的差别的。


---------------------------------------------版本回退--------------------------------------------------

1、版本回退
	使用git log 命令查看当前文件已有的历史版本
	使用git log --pretty=oneline可以查看简化的历史版本
	使用git reset --hard HEAD^ 回退到上一版本，
		HEAD表示当前版本的指针，HEAD^表示上一版本，HEAD^^表示回退两个版本，HEAD~100，表示回退一百个版本
	
	如果想要回退到已经被回退到的之前那个版本，也就是回退之后反悔了，想退回去
	使用git reset --hard 1094a，后面的1094a表示一个版本的版本号，只要知道版本号可以回退到任意版本
	使用git reflog可以查看历次的版本号
	
注意：
	hard参数的意义是：
	
	
	
	
	