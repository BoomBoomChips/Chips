package com.videostudy.springboot_2_user.mapper;


import com.videostudy.springboot_2_user.pojo.User;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper extends tk.mybatis.mapper.common.Mapper<User> {
}
