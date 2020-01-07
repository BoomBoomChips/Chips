package com.springcloud_3_provider.service;


import com.springcloud_3_provider.mapper.UserMapper;
import com.springcloud_3_provider.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    @Autowired
    public UserMapper userMapper;

    public User queryUserById(Long id){
        return this.userMapper.selectByPrimaryKey(id);
    }
}
