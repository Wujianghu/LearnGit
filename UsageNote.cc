//time:2022年1月16日21:37:52

---------------------------------------------安装Git--------------------------------------------------

1、在Windows上安装Git，安装完毕之后，初始化姓名邮箱
	git config --global user.name "Your Name"
	git config --global user.email "email@example.com"
2、注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置



---------------------------------------------创建版本库方法-------------------------------------------

1、创建一个空的GitHub命令是
	mkdir flodername
	cd  flodername
	pwd  //显示你当前所在位置

2、初始化版本库
	使用命令 git init


	
3、添加（上传）一个文件，需要分三步
	1）先在本地创建一个文件（比如txt、md、c等）//最好不要使用记事本创建，可以更改为.c文件用notepad++写
		创建文件 touch FileName.txt
		删除文件 rm  FileName.txt
	2）使用 git add  filename.txt   //将本地的文件添加到暂存区，可反复多次添加工作区的修改，最后一次性提交，就会全部提交。
		如果添加了
	3）使用 git commit -m "添加提交说明"  //将添加的文件提交到GitHub，可以一次添加多个文件
特别提醒：以上所有命令操作都是在自己的GitHub里面操作。

---------------------------------------------查看修改--------------------------------------------------

p1、修改文件后查看提交状态
	git status//查看工作区是否有需要有添加和提交的文件
	git diff  //对比展示详细的修改区别
	git add    
	git commit //再次重新添加和提交已修改的文件，完成提交
	
注意：
	p1）要明白这3个概念，工作区（working tree），暂存区（index /stage），仓库（repository）
		git跟不同的参数，比较不同的区间的版本。
		git diff：是查看working tree与index的差别的，就是查看工作区修改的，有没有添加到暂存区，没添加到，就有不同。
		git diff --cached：是查看index与repository的差别的，查看已经添加到暂存区的有没有提交，没提交，就有不同。
		git diff HEAD：是查看working tree和repository的差别的。其中：HEAD代表的是最近的一次commit的信息。直接查询工作区做的修改有没有提交到仓库
	综上所述：git diff 后面跟文件名称是是查看工作区（working tree）与暂存区（index）的差别的。
	


---------------------------------------------版本回退--------------------------------------------------

p1、版本回退
	使用git log 命令查看当前文件已有的历史版本
	使用git log --pretty=oneline可以查看简化的历史版本
	使用git reset --hard HEAD^ 回退到上一版本，
		HEAD表示当前版本的指针，HEAD^表示上一版本，HEAD^^表示回退两个版本，HEAD~100，表示回退一百个版本
	如果想要回退到已经被回退到的之前那个版本，也就是回退之后反悔了，想退回去
	使用git reset --hard 1094a，后面的1094a表示一个版本的版本号，只要知道版本号可以回退到任意版本
	使用git reflog可以查看历次的版本号
	
	
注意：
	//hard参数的意义是：
	
	
	
---------------------------------------------工作区和暂存区--------------------------------------------
	工作区（Working Directory）
	就是你在电脑里能看到的目录，比如我的learngit文件夹就是一个工作区：

	版本库（Repository）
	工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。
	Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。
	
	前面讲了我们把文件往Git版本库里添加的时候，是分两步执行的：
	第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；
	第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

	因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。
	你可以简单理解为，需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。

注意（网友补充）：
	Git管理的文件分为：工作区，版本库，版本库又分为暂存区stage和暂存区分支master(仓库)
	工作区>>>暂存区>>>仓库
	git add把文件从工作区>>>暂存区，git commit把文件从暂存区>>>仓库，
	git diff查看工作区和暂存区差异，
	git diff --cached查看暂存区和仓库差异，
	git diff HEAD 查看工作区和仓库的差异，
	git add的反向命令git checkout，撤销工作区修改，即把暂存区最新版本转移到工作区，
	git commit的反向命令git reset HEAD，就是把仓库最新版本转移到暂存区。


---------------------------------------------撤销修改--------------------------------------------------
	p1、撤销工作区的修改：
	git resotre --worktree readme.txt
	
	p2、从master恢复暂存区 
	git restore --staged readme.txt
	
	p3、从master同时恢复工作区和暂存区   //没有修改成功，评论区意见不一，没有更好的
	git restore --source=HEAD --staged --worktree readme.txt


---------------------------------------------删除文件--------------------------------------------------
删除文件
从工作区删除文件用 rm filename
从暂存区删除已经添加的文件用 git rm filename
从版本库删除文件  

'讲的不是很清楚，后面再整理'



---------------------------------------------添加远程仓库--------------------------------------------------
1添加GitHub上传确认秘钥
p1、在Windows的目录C:\Users\JZ007下查看有无.ssh文件夹，有的话包含id_rsa和id_rsa.pub两个文件；
	这两个就是SSH Key的秘钥对，id_rsa是私钥，不能泄露出去，id_rsa.pub是公钥，可以放心地告诉任何人。
p2、如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：
	输入命令：$ ssh-keygen -t rsa -C "youremail@example.com"
	把邮件地址换成自己常用邮件地址，然后一路回车，使用默认值即可，非军事目的，所以也无需设置密码。
	继续在C:\Users\JZ007下查看这两个文件
p3、登陆GitHub，打开“Account settings”，“SSH Keys”页面：
	然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴id_rsa.pub文件的内容：
	点“Add Key”，你就应该看到已经添加的Key：
p4、Git支持SSH协议，所以，GitHub只要知道了你的公钥，就可以确认只有你自己才能推送。
	GitHub允许你添加多个Key。假定你有若干电脑，你一会儿在公司提交，一会儿在家里提交，只要把每台电脑的Key都添加到GitHub，就可以在每台电脑上往GitHub推送了
	在GitHub上免费托管的Git仓库，任何人都可以看到喔（但只有你自己才能改）。所以，不要把敏感信息放进去。
网友补充：
	ssh key和github都是多对多的

2将本地仓库推送到远程仓库并关联起来
p1、在GitHub新建Repository，命名与本地一样
p2、使用 git remote add origin git@github.com:JZ007WJH/FloderName.git，将本地仓库与远程仓库关联起来，远程库的名字就是origin，这是Git默认的叫法，也可以改成别的；JZ007WJH替换成你自己的GitHub账户名
p3、使用git push -u origin master，把本地库的所有内容推送到远程库上；第一次使用Git的clone或者push命令连接GitHub时，会得到一个提示，这是因为Git使用SSH连接，而SSH连接在第一次验证GitHub服务器的Key时，需要你确认GitHub的Key的指纹信息是否真的来自GitHub的服务器，输入yes回车即可。
Git会输出一个警告，告诉你已经把GitHub的Key添加到本机的一个信任列表里了

3删除远程仓库
p1、先在Git bash上用git remote -v 查看关联版本
p2、用git remote rm origin取消关联  
p3、在GitHub上该项目设置的最下面删除

4先建立远程仓库再clone到本地
注意使用ssh方式会更快，但是工作后有一些公司仅支持http协议
举例clone新建的GitSkills仓库
ssh方式：git clone git@github.com:JZ007WJH/gitskills.git
https方式： git clone https://github.com/JZ007WJH/GitSkills.git

---------------------------------------------分支--------------------------------------------------
Git鼓励大量使用分支：

查看分支：git branch

创建分支：git branch <name>

切换分支：git checkout <name>或者git switch <name>

创建+切换分支：git checkout -b <name>或者git switch -c <name>

合并某分支到当前分支：git merge <name>

删除分支：git branch -d <name>


------------------------------------分支冲突及处理--------------------------------------------------
1冲突怎么来的
	新建一个分支，修改，添加、提交之后
	切换到其他分支如master分支，继续修改该处，添加、提交
	这样操作之后，相当于有同一个文件同一处有两份来自不同分支提交的修改
	如果使用git merge 命令合并  会显示合并冲突 无法完成合并
	//处于合并冲突状态时，不能切换分支也不能再次合并，用git merge --abort命令退出合并状态
2、解决办法
	此时 可以用cat查看文件   用vim修改文件  删除冲突部分并修正//cat 和vim 都无需加git前缀 
	使用git log --graph 命令图示分支之间冲突关系
	然后再次添加、提交，并切换到另外一个分支下，用git merge命令合并刚修改的这个分支
	两个分支就一样了//time:2022年1月16日21:37:52

---------------------------------------------安装Git--------------------------------------------------

1、在Windows上安装Git，安装完毕之后，初始化姓名邮箱
	git config --global user.name "Your Name"
	git config --global user.email "email@example.com"
2、注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置



---------------------------------------------创建版本库方法-------------------------------------------

1、创建一个空的GitHub命令是
	mkdir flodername
	cd  flodername
	pwd  //显示你当前所在位置

2、初始化版本库
	使用命令 git init


	
3、添加（上传）一个文件，需要分三步
	1）先在本地创建一个文件（比如txt、md、c等）//最好不要使用记事本创建，可以更改为.c文件用notepad++写
		创建文件 touch FileName.txt
		删除文件 rm  FileName.txt
	2）使用 git add  filename.txt   //将本地的文件添加到暂存区，可反复多次添加工作区的修改，最后一次性提交，就会全部提交。
		如果添加了
	3）使用 git commit -m "添加提交说明"  //将添加的文件提交到GitHub，可以一次添加多个文件
特别提醒：以上所有命令操作都是在自己的GitHub里面操作。

---------------------------------------------查看修改--------------------------------------------------

p1、修改文件后查看提交状态
	git status//查看工作区是否有需要有添加和提交的文件
	git diff  //对比展示详细的修改区别
	git add    
	git commit //再次重新添加和提交已修改的文件，完成提交
	
注意：
	p1）要明白这3个概念，工作区（working tree），暂存区（index /stage），仓库（repository）
		git跟不同的参数，比较不同的区间的版本。
		git diff：是查看working tree与index的差别的，就是查看工作区修改的，有没有添加到暂存区，没添加到，就有不同。
		git diff --cached：是查看index与repository的差别的，查看已经添加到暂存区的有没有提交，没提交，就有不同。
		git diff HEAD：是查看working tree和repository的差别的。其中：HEAD代表的是最近的一次commit的信息。直接查询工作区做的修改有没有提交到仓库
	综上所述：git diff 后面跟文件名称是是查看工作区（working tree）与暂存区（index）的差别的。
	


---------------------------------------------版本回退--------------------------------------------------

p1、版本回退
	使用git log 命令查看当前文件已有的历史版本
	使用git log --pretty=oneline可以查看简化的历史版本
	使用git reset --hard HEAD^ 回退到上一版本，
		HEAD表示当前版本的指针，HEAD^表示上一版本，HEAD^^表示回退两个版本，HEAD~100，表示回退一百个版本
	如果想要回退到已经被回退到的之前那个版本，也就是回退之后反悔了，想退回去
	使用git reset --hard 1094a，后面的1094a表示一个版本的版本号，只要知道版本号可以回退到任意版本
	使用git reflog可以查看历次的版本号
	
	
注意：
	//hard参数的意义是：
	
	
	
---------------------------------------------工作区和暂存区--------------------------------------------
	工作区（Working Directory）
	就是你在电脑里能看到的目录，比如我的learngit文件夹就是一个工作区：

	版本库（Repository）
	工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。
	Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。
	
	前面讲了我们把文件往Git版本库里添加的时候，是分两步执行的：
	第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；
	第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

	因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。
	你可以简单理解为，需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。

注意（网友补充）：
	Git管理的文件分为：工作区，版本库，版本库又分为暂存区stage和暂存区分支master(仓库)
	工作区>>>暂存区>>>仓库
	git add把文件从工作区>>>暂存区，git commit把文件从暂存区>>>仓库，
	git diff查看工作区和暂存区差异，
	git diff --cached查看暂存区和仓库差异，
	git diff HEAD 查看工作区和仓库的差异，
	git add的反向命令git checkout，撤销工作区修改，即把暂存区最新版本转移到工作区，
	git commit的反向命令git reset HEAD，就是把仓库最新版本转移到暂存区。


---------------------------------------------撤销修改--------------------------------------------------
	p1、撤销工作区的修改：
	git resotre --worktree readme.txt
	
	p2、从master恢复暂存区 
	git restore --staged readme.txt
	
	p3、从master同时恢复工作区和暂存区   //没有修改成功，评论区意见不一，没有更好的
	git restore --source=HEAD --staged --worktree readme.txt


---------------------------------------------删除文件--------------------------------------------------
删除文件
	从工作区删除文件用 rm filename
	从暂存区删除已经添加的文件用 git rm filename
	从版本库删除文件  

	'讲的不是很清楚，后面再整理'



---------------------------------------------添加远程仓库--------------------------------------------------
1添加GitHub上传确认秘钥
	p1、在Windows的目录C:\Users\JZ007下查看有无.ssh文件夹，有的话包含id_rsa和id_rsa.pub两个文件；
		这两个就是SSH Key的秘钥对，id_rsa是私钥，不能泄露出去，id_rsa.pub是公钥，可以放心地告诉任何人。
	p2、如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：
		输入命令：$ ssh-keygen -t rsa -C "youremail@example.com"
		把邮件地址换成自己常用邮件地址，然后一路回车，使用默认值即可，非军事目的，所以也无需设置密码。
		继续在C:\Users\JZ007下查看这两个文件
	p3、登陆GitHub，打开“Account settings”，“SSH Keys”页面：
		然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴id_rsa.pub文件的内容：
		点“Add Key”，你就应该看到已经添加的Key：
	p4、Git支持SSH协议，所以，GitHub只要知道了你的公钥，就可以确认只有你自己才能推送。
		GitHub允许你添加多个Key。假定你有若干电脑，你一会儿在公司提交，一会儿在家里提交，只要把每台电脑的Key都添加到GitHub，就可以在每台电脑上往GitHub推送了
		在GitHub上免费托管的Git仓库，任何人都可以看到喔（但只有你自己才能改）。所以，不要把敏感信息放进去。
	网友补充：
		ssh key和github都是多对多的

2将本地仓库推送到远程仓库并关联起来
	p1、在GitHub新建Repository，命名与本地一样
	p2、使用 git remote add origin git@github.com:JZ007WJH/FloderName.git，
		将本地仓库与远程仓库关联起来，远程库的名字就是origin，这是Git默认的叫法，
		也可以改成别的；JZ007WJH替换成你自己的GitHub账户名
	p3、使用git push -u origin     master，把本地库的所有内容推送到远程库上；
		第一次使用Git的clone或者push命令连接GitHub时，会得到一个提示，
		这是因为Git使用SSH连接，而SSH连接在第一次验证GitHub服务器的Key时，
		需要你确认GitHub的Key的指纹信息是否真的来自GitHub的服务器，输入yes回车即可。
		Git会输出一个警告，告诉你已经把GitHub的Key添加到本机的一个信任列表里了

3删除远程仓库
	p1、先在Git bash上用git remote -v 查看关联版本
	p2、用git remote rm origin取消关联  
	p3、在GitHub上该项目设置的最下面删除

4先建立远程仓库再clone到本地
	注意使用ssh方式会更快，但是工作后有一些公司仅支持http协议
	举例clone新建的GitSkills仓库
	ssh方式：git clone git@github.com:JZ007WJH/gitskills.git
	https方式： git clone https://github.com/JZ007WJH/GitSkills.git

---------------------------------------------分支--------------------------------------------------
Git鼓励大量使用分支：
	查看分支：git branch
	创建分支：git branch <name>
	切换分支：git checkout <name>或者git switch <name>
	创建+切换分支：git checkout -b <name>或者git switch -c <name>
	合并某分支到当前分支：git merge <name>
	删除分支：git branch -d <name>


------------------------------------分支冲突及处理--------------------------------------------------
1冲突怎么来的
	新建一个分支，修改，添加、提交之后
	切换到其他分支如master分支，继续修改该处，添加、提交
	这样操作之后，相当于有同一个文件同一处有两份来自不同分支提交的修改
	如果使用git merge 命令合并  会显示合并冲突 无法完成合并
	//处于合并冲突状态时，不能切换分支也不能再次合并，用git merge --abort命令退出合并状态
2、解决办法
	此时 可以用cat查看文件   用vim修改文件  删除冲突部分并修正//cat 和vim 都无需加git前缀 
	使用git log --graph 命令图示分支之间冲突关系
	然后再次添加、提交，并切换到另外一个分支下，用git merge命令合并刚修改的这个分支
	两个分支就一样了
	
	
------------------------------------分支管理策略----------------------------------------------------
通常，合并分支时，如果可能，Git会用Fast forward模式，但这种模式下，删除分支后，会丢掉分支信息。
如果要强制禁用Fast forward模式，Git就会在merge时生成一个新的commit，这样，从分支历史上就可以看出分支信息。
使用git merge --no-ff -m "merge with no-ff" dev     //--no-ff禁用Fast forward模式

分支使用策略
	master分支应该是非常稳定的，也就是仅用来发布新版本，平时不能在上面干活；
	干活都在dev分支上，也就是说，dev分支是不稳定的，到某个时候，比如01版本发布时，再把dev分支合并到master上，在master分支发布01版本；
	你和你的小伙伴们每个人都在dev分支上干活，每个人都有自己的分支，时不时地往dev分支上合并就可以了。
	
	合并分支时，加上--no-ff参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而fast forward合并就看不出来曾经做过合并。
	
	
-----------------------------------Bug分支切换保护现场---------------------------------------------------
情景：
	当前dev分支上活没干完，要切换到其他bug修复分支
	Git还提供了一个stash功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作
	使用命令git stash 暂存工作区内容
	
	其他分支任务完成 切回dev  
	使用 git stash list查看现有的stash列表
	恢复，有两个办法：

	方式一是用git stash apply
		恢复后，stash内容并不删除，你需要用git stash drop来删除；

	方式二是用git stash pop，恢复的同时把stash内容也删了：
	
	当前被保存的分支没有加入刚刚bug修复的修改量
	Git专门提供了一个cherry-pick命令，
	让我们能复制一个特定的提交到当前分支：
	使用git cherry-pick 版本号即可修复
	
	//惨痛教训
	我因为恢复时候没有将现有的内容做一个保存，这部分的笔记我做了两遍
	
	--------------------------------------删除还没有被合并的分支---------------------------------------------------
	开发一个新feature，最好新建一个分支；

	如果要丢弃一个没有被合并过的分支，可以通过git branch -D <name>强行删除。
	
-----------------------------------多人协作---------------------------------------------------
1、多人协作的工作模式通常是这样：

	首先，可以试图用git push origin <branch-name>推送自己的修改；

	如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；

	如果合并有冲突，则解决冲突，并在本地提交；

	没有冲突或者解决掉冲突后，再用git push origin <branch-name>推送就能成功！

	如果git pull提示no tracking information，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream-to <branch-name> origin/<branch-name>。
	
2、小结
	查看远程库信息，使用git remote -v；
	本地新建的分支如果不推送到远程，对其他人就是不可见的；
	从本地推送分支，使用git push origin branch-name，如果推送失败，先用git pull抓取远程的新提交；
	
	在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，
	本地和远程分支的名称最好一致；

	建立本地分支和远程分支的关联，使用git branch --set-upstream branch-name origin/branch-name；

	从远程抓取分支，使用git pull，如果有冲突，要先处理冲突。
	

-----------------------------------Rebase---------------------------------------------------
	rebase操作的特点：把分叉的提交历史“整理”成一条直线，看上去更直观。缺点是本地的分叉提交已经被修改过了。
	
	小结
	rebase操作可以把本地未push的分叉提交历史整理成直线；
	rebase的目的是使得我们在查看历史提交的变化时更容易，因为分叉的提交需要三方对比。
	
-----------------------------------打标签---------------------------------------------------
小结
	命令git tag <tagname>用于新建一个标签，默认为HEAD，也可以指定一个commit id；

	命令git tag -a <tagname> -m "blablabla..."可以指定标签信息；

	命令git tag可以查看所有标签。

	
	
	

