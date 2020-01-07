package com.videostudy.springboot_2_user.service;


import com.videostudy.springboot_2_user.mapper.UserMapper;
import com.videostudy.springboot_2_user.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class UserService {

    @Autowired
    private UserMapper userMapper;

    public User queryUserById(Long id) {
        return this.userMapper.selectByPrimaryKey(id);
    }

    @Transactional
    public void deleteUserById(Long id) {
        this.userMapper.deleteByPrimaryKey(id);
    }

    public List<User> queryUserAll() {
        return this.userMapper.selectAll();
    }
}
