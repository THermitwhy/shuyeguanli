function getSql(sqlId)--获取sql
    --print("you have load")
    local sql = require "libcToLua"
    local sqls="select SQL1 from XT_SELECTSQL1 where SQLID="..sqlId
    local sqlState1,sqlState2=sql.sqlToLua(sqls)
    return sqlState2[1][1] 
end

function getResult(sqls)--获取结果
    --print("you have load")
    local sql = require "libcToLua"
    local sqlState1,sqlState2=sql.sqlToLua(sqls)
    print(sqlState2[1][1])
    return sqlState1,sqlState2
end


function UserAuthentication(tab)--用户认证
    --local sql = require "libcToLua"
    print("you have load")
    
    --print("tab[1]="..tab[1])
    local sqls
    if(tab[1]~=nil and tab[2]~=nil)
    then
        print("tab[1]="..tab[1])
        sqls="select count(user) from gy_ceshiyh where user='"..tab[1].."' and userid='"..tab[2].."'"
        --sqls="select user from gy_ceshiyh"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function getBingrenxx(tab)--查询病人信息
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select xingming from gy_bingrenxx where bingrenid='"..tab[1].."'"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function getShuyebr(tab)--查询待输液病人信息 select distinct xingming from sy_shuyesqd where A0=1 and dangqianzt<2 and benyuancs>yizhixcs
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select distinct xingming from sy_shuyesqd where "..tab[1].."=1 and dangqianzt<2 and benyuancs>yizhixcs"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function getShuyesqd(tab)--获取输液申请单id
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select shenqingdid from sy_shuyesqd where xingming='"..tab[1].."' and benyuancs>yizhixcs"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function getShuyekxx(tab)--获取输液卡信息 select a.shenqingdid,a.benyuancs,a.yizhixcs,b.yaopinmc,b.yicijl,b.yicijldw,a.dangqianzt from sy_shuyesqd a,mz_chufang2 b where a.shenqingdid=b.shenqingdid and a.shenqingdid in (A0)
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select a.shenqingdid,a.benyuancs,a.yizhixcs,b.yaopinmc,b.yicijl,b.yicijldw,a.dangqianzt from sy_shuyesqd a,mz_chufang2 b where a.shenqingdid=b.shenqingdid and a.shenqingdid in ("..tab[1]..")"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function userDoubleVerity(tab)--护士皮试双签名 select count(user) from (select a.user from gy_ceshiyh a where a.user='A0' and a.`password`='A1' union select b.user from gy_ceshiyh b  where b.user ='A2' and b.`password`='A3') as c
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil and tab[2]~=nil and tab[3]~=nil and tab[4]~=nil)
    then
        sqls="select count(user) from (select a.user from gy_ceshiyh a where a.user='"..tab[1].."' and a.`password`='"..tab[2].."' union select b.user from gy_ceshiyh b  where b.user ='"..tab[3].."' and b.`password`='"..tab[4].."') as c"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function waitPishibr(tab)--获取待皮试病人信息 select distinct xingming from ps_pishisqd where A0=1  and pishijg is null
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select distinct xingming from ps_pishisqd where "..tab[1].."=1 and pishijg is null"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function getBasicShuyeMess(tab)--获取输液基本信息 select shenqingdid,xingming,pishiyp from ps_pishisqd where xingming='A0'  and pishijg is null
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="select shenqingdid,xingming,pishiyp from ps_pishisqd where xingming='"..tab[1].."' and pishijg is null"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=1
    return result1,result2,param
end

function updateShuyeCount(tab)--更新输液次数 update sy_shuyesqd set yizhixcs=yizhixcs+1,dangqianzt=0 where shenqingdid='A0'
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="update sy_shuyesqd set yizhixcs=yizhixcs+1,dangqianzt=0 where shenqingdid='"..tab[1].."'"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=2
    return result1,result2,param
end

function updateShuyezt(tab)--更新输液状态 update sy_shuyesqd set dangqianzt=1 where shenqingdid='A0'
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil)
    then
        sqls="update sy_shuyesqd set dangqianzt=1 where shenqingdid='"..tab[1].."'"
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=2
    return result1,result2,param
end

function updatePishiJG(tab)--更新皮试结果 update ps_pishisqd set pishijg='A0' where shenqingdid=A1
    --local sql = require "libcToLua"
    print("you have load")
    local sqls
    if(tab[1]~=nil and tab[2]~=nil)
    then
        sqls="update ps_pishisqd set pishijg='"..tab[1].."' where shenqingdid="..tab[2]
    else
        print("error")
        return
    end
    print("sqls="..sqls)
    local result1,result2=getResult(sqls)
    local param=2
    return result1,result2,param
end

function add(tab)--添加
    local a={"1","2"}
    local b={"3","4"}
    local c={a,b}
    return c
end

function TypeJudgment(sqlid,tab)--类型判断
    local tablefunc={}
    tablefunc[1]=UserAuthentication
    tablefunc[2]=getBingrenxx
    tablefunc[3]=getShuyebr
    tablefunc[4]=getShuyesqd
    tablefunc[5]=getShuyekxx
    tablefunc[6]=userDoubleVerity
    tablefunc[7]=waitPishibr
    tablefunc[8]=getBasicShuyeMess
    tablefunc[2006]=updateShuyeCount
    tablefunc[2007]=updateShuyezt
    tablefunc[2008]=updatePishiJG
    print(sqlid)
    return tablefunc[sqlid](tab)
end

